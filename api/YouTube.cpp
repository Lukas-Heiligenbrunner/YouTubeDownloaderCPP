//
// Created by lukas on 07.04.19.
//

#include "YouTube.h"

static const std::string apikey = "AIzaSyAYIXX7lgATXN2xPSCIK71wNQjgUzmYL0s";

std::string YouTube::searchYouTube(std::string query) {
    Hashmap<std::string,std::string> mymap;

    mymap.add("q",query);
    mymap.add("type","video");
    mymap.add("maxResults","25");
    mymap.add("part","snippet");
    mymap.add("key",apikey);

    return request("https://www.googleapis.com/youtube/v3/search",false,mymap);
}
