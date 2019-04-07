//
// Created by lukas on 06.04.19.
//

#include "API.h"

#include <string>
#include <stdio.h>

#include <curl/curl.h>
#include <iostream>

std::string API::request(std::string myurl) {

    CURL *curl;
    FILE *fp;
    CURLcode res;
    const char *url =myurl.c_str();

    char outfilename[FILENAME_MAX] = "bbb.txt";
    curl = curl_easy_init();
    std::string readString;
    if (curl) {
        fp = fopen(outfilename,"wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);

        //ssl verification
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readString);

        res = curl_easy_perform(curl);
        /* always cleanup */
        curl_easy_cleanup(curl);
        fclose(fp);



        std::cout << "value: " << readString << "\n";
    }


    return std::__cxx11::string();
}

size_t API::write_data(void *contents, size_t size, size_t nmemb, FILE *stream) {

//    size_t written = fwrite(contents, size, nmemb, stream);
//    return written;

//    size_t realsize = size * nmemb;
//    readString.append(contents, realsize);
//    return realsize;

    ((std::string*)stream)->append((char*)contents, size * nmemb);
    return size * nmemb;
}
