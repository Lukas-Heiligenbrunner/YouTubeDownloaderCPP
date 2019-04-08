//
// Created by lukas on 07.04.19.
//

#include <datatypes/json.h>
#include "YouTubeToLink.h"

std::string YouTubeToLink::getDownloadLink(std::string videoid) {
    std::string reply = getDownloadLinkJson(videoid);

    json::JSON obj = json::JSON::Load(reply);

    downloadUrl = obj["link"].ToString();
    filename = obj["title"].ToString();
    filelength = obj["length"].ToString();

    return obj["link"].ToString();
}

std::string YouTubeToLink::getDownloadLinkJson(std::string videoid) {
    Hashmap<std::string,std::string> mymap;

    mymap.add("format","JSON");
    mymap.add("video","https://www.youtube.com/watch?v="+videoid);

    std::string reply = request("http://www.convertmp3.io/fetch/",false,mymap);
    return reply;
}

std::string YouTubeToLink::getFileName() {
    return filename;
}
