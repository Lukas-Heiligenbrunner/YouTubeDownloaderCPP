//
// Created by lukas on 06.04.19.
//

#include "API.h"

#include <string>
#include <iostream>

#include <stdio.h>
#include <curl/curl.h>

#include <datatypes/Hashmap.h>

std::string API::request(std::string myurl) {
    Hashmap<std::string,std::string> map;
    return request(myurl,false,map);
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
            std::string poststring;
            for (int i = 0; i < map.size(); i++) {
                poststring+=map.getValue(i)+"="+map.getKey(i);
                if(i < map.size()-1){
                    poststring+="&";
                }
            }
            curl_easy_setopt(curl, CURLOPT_POST, 1);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, poststring.c_str());
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

        curl_easy_setopt(curl, CURLOPT_URL, myurl.c_str());

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readString);

        res = curl_easy_perform(curl);

        curl_easy_cleanup(curl);
    }
    return readString;
}

size_t API::write_data(void *contents, size_t size, size_t nmemb, FILE *stream) {
    ((std::string*)stream)->append((char*)contents, size * nmemb);
    return size * nmemb;
}
