//
// Created by lukas on 07.04.19.
//

#include <datatypes/json.h>
#include "YouTube.h"

const std::string YouTube::apikey = "AIzaSyAYIXX7lgATXN2xPSCIK71wNQjgUzmYL0s";

std::string YouTube::searchYouTube(std::string query) {
    Hashmap<std::string,std::string> mymap;

    mymap.add("q",query);
    mymap.add("type","video");
    mymap.add("maxResults","25");
    mymap.add("part","snippet");
    mymap.add("key",apikey);

    std::string reply = request("https://www.googleapis.com/youtube/v3/search",false,mymap);



    return reply;
}

std::string YouTube::firstResultID(std::string keyword) {
    std::string reply = searchYouTube(keyword);
    json::JSON obj;

    obj = json::JSON::Load(reply);

    return obj["items"][0]["id"]["videoId"].ToString();
}
