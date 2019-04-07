//
// Created by lukas on 06.04.19.
//

#include "API.h"

#include <string>
#include <stdio.h>

#include <curl/curl.h>
#include <iostream>
#include <datatypes/Hashmap.h>

std::string API::request(std::string myurl) {
    Hashmap<std::string,std::string> map;
    return request(myurl,false,map);
}

size_t API::write_data(void *contents, size_t size, size_t nmemb, FILE *stream) {
    ((std::string*)stream)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string API::request(std::string myurl, bool post, Hashmap<std::string,std::string> &map) {
    CURL *curl;
    CURLcode res;


    curl = curl_easy_init();
    std::string readString;
    if (curl) {


        //ssl verification
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        if(post){
            curl_easy_setopt(curl, CURLOPT_POST, 1);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "name=Bjarne&comment=example");
        }else{
            std::string getstring;
            for(int i =0; i< map.size();i++){
                getstring+=map.getKey(i)+"="+map.getValue(i);
                if(i < map.size()-1){
                    getstring+="&";
                }
            }

            myurl+="?"+getstring;
        }

        const char *url =myurl.c_str();
        curl_easy_setopt(curl, CURLOPT_URL, url);


        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readString);

        res = curl_easy_perform(curl);

        curl_easy_cleanup(curl);
    }
    return readString;
}
