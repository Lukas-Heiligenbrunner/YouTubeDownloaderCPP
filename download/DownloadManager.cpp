//
// Created by lukas on 07.04.19.
//

#include <string>
#include <curl/curl.h>
#include <iostream>
#include "DownloadManager.h"

int DownloadManager::loadedsize = 0;

size_t DownloadManager::write_data(void *buffer, size_t size, size_t buffersize, FILE *stream) {
    size_t written = fwrite(buffer, size, buffersize, stream);
    //loadedsize+= sizeof(buffer);
    loadedsize+=buffersize;
    std::cout << loadedsize << "\n";
    //TODO callback or event to handle percent change
    return written;
}

void DownloadManager::downloadUrl(std::string url) {
    CURL *curl;
    FILE *fp;
    CURLcode res;
    char outfilename[FILENAME_MAX] = "test.mp3";
    //TODO individual input file and remove test souts;
    curl = curl_easy_init();
    std::cout << "inited\n";
    std::cout << url << "<<<< link\n";
    if (curl) {
        fp = fopen(outfilename,"wb");
        //ssl verification
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        std::cout << "requesting\n";
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl,CURLOPT_FOLLOWLOCATION,1L);
        curl_easy_setopt(curl,CURLOPT_BUFFERSIZE,1024);

        std::cout << "perform\n";
        res = curl_easy_perform(curl);
        /* always cleanup */
        curl_easy_cleanup(curl);
        fclose(fp);
        std::cout << "closed\n";
    }
}
