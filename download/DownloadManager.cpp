//
// Created by lukas on 07.04.19.
//

#include <string>
#include <curl/curl.h>
#include <iostream>
#include <vector>
#include <functional>
#include "DownloadManager.h"

#include <thread>

int DownloadManager::loadedsize = 0;
int DownloadManager::totalfilesize = 0;
std::vector<std::function<void(double percent)>> DownloadManager::listeners;
std::vector<std::function<void()>> DownloadManager::finishedlisteners;

size_t DownloadManager::write_data(void *buffer, size_t size, size_t buffersize, FILE *stream) {
    size_t written = fwrite(buffer, size, buffersize, stream);
    loadedsize += buffersize;

    double percent = (double) loadedsize * 100 / (double) totalfilesize;
    firePercentEvent(percent);
    return written;
}

void DownloadManager::downloadUrl(std::string url, std::string filename) {
    std::thread thread = std::thread([url, filename, this] {


        CURL *curl;
        FILE *fp;
        CURLcode res;
        loadedsize = 0;
        totalfilesize = 0;
        curl = curl_easy_init();

        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        curl_easy_setopt(curl, CURLOPT_NOBODY, 1);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
        curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 500);


        curl_easy_perform(curl);

        curl_easy_getinfo(curl, CURLINFO_CONTENT_LENGTH_DOWNLOAD_T, &totalfilesize);

        curl = curl_easy_init();
        std::cout << "size:: " << totalfilesize << "\n";

        if (curl) {
            fp = fopen(filename.c_str(), "wb");
            //ssl verification
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(curl, CURLOPT_BUFFERSIZE, 1024);

            res = curl_easy_perform(curl);

            /* always cleanup */
            curl_easy_cleanup(curl);
            fclose(fp);
            this->fireFinishedEvent();
        } else {
            //TODO fire error event
        }
    });
    thread.detach();
}

void DownloadManager::onDownloadPercentChange(std::function<void(double percent)> listener) {
    listeners.push_back(listener);
}


void DownloadManager::firePercentEvent(double percent) {
    for (int i = 0; i < listeners.size(); ++i) {
        listeners.at(i)(percent);
    }
}

double DownloadManager::getPercent() {
    return (double) loadedsize * 100 / (double) totalfilesize;
}

void DownloadManager::onFinishedListener(std::function<void()> listener) {
    finishedlisteners.push_back(listener);
}

void DownloadManager::fireFinishedEvent() {
    for (int i = 0; i < finishedlisteners.size(); ++i) {
        finishedlisteners.at(i)();
    }
}
