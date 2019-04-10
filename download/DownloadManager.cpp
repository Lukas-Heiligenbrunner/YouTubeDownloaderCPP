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
std::vector<std::function<void(int percent)>> DownloadManager::listeners;
std::vector<std::function<void()>> DownloadManager::finishedlisteners;

size_t DownloadManager::write_data(void *buffer, size_t size, size_t buffersize, FILE *stream) {
    size_t written = fwrite(buffer, size, buffersize, stream);
    //loadedsize+= sizeof(buffer);
    loadedsize += buffersize;
    //std::cout << loadedsize << "\n";
    //TODO calculate percent
    firePercentEvent(loadedsize);
    return written;
}


void DownloadManager::downloadUrl(std::string url, std::string filename) {
    std::thread thread = std::thread([url,filename,this] {


        CURL *curl;
        FILE *fp;
        CURLcode res;
        curl = curl_easy_init();
        std::cout << "inited\n";
        std::cout << url << "<<<< link\n";

        //TODO read somehow the filesize of the music file to download

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
            this->fireFinishedEvent(); //TODO terminates application !?!?!?
        } else{
            //TODO fire error event
        }
    });
    thread.detach();
}

void DownloadManager::onDownloadPercentChange(std::function<void(int percent)> listener) {
    listeners.push_back(listener);
}


void DownloadManager::firePercentEvent(int percent) {
    for (int i = 0; i < listeners.size(); ++i) {
        listeners.at(i)(percent);
    }
}

int DownloadManager::getPercent() {
    //TODO calc the percent of the downloaded file
    return 0;
}

void DownloadManager::onFinishedListener(std::function<void()> listener) {
    finishedlisteners.push_back(listener);
}

void DownloadManager::fireFinishedEvent() {
    for (int i = 0; i < finishedlisteners.size(); ++i) {
        finishedlisteners.at(i)();
    }
}
