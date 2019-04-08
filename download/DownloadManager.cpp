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
std::vector<std::function<void()>> DownloadManager::listeners;

size_t DownloadManager::write_data(void *buffer, size_t size, size_t buffersize, FILE *stream) {
    size_t written = fwrite(buffer, size, buffersize, stream);
    //loadedsize+= sizeof(buffer);
    loadedsize += buffersize;
    std::cout << loadedsize << "\n";
    fireEvent();
    return written;
}


void DownloadManager::downloadUrl(std::string url, std::string filename) {
    std::thread thread = std::thread([url,filename] {


        CURL *curl;
        FILE *fp;
        CURLcode res;
        curl = curl_easy_init();
        std::cout << "inited\n";
        std::cout << url << "<<<< link\n";

        //TODO read somehow the filesize of the music file to download
//        curl_off_t cl;
//        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
//        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
//        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
//
//        //curl_easy_setopt(curl, CURLOPT_HEADER, 1);
//        curl_easy_setopt(curl, CURLOPT_NOBODY, 1);
//
//        curl_easy_getinfo(curl, CURLINFO_CONTENT_LENGTH_DOWNLOAD_T, &cl);
//        res = curl_easy_perform(curl);
//
//        std::cout << "filesize is: " << cl << "\n";
//
//        curl = curl_easy_init();


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
            std::cout << "closed\n";
        }
    });
    thread.detach();
}

void DownloadManager::addActionListener(std::function<void()> test) {
    listeners.push_back(test);
}

void DownloadManager::fireEvent() {
    for (int i = 0; i < listeners.size(); ++i) {
        listeners.at(i)();
    }
}

int DownloadManager::getPercent() {
    //TODO calc the percent of the downloaded file
    return 0;
}
