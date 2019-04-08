//
// Created by lukas on 07.04.19.
//

#ifndef QT5PROJECT_YOUTUBETOLINK_H
#define QT5PROJECT_YOUTUBETOLINK_H


#include "API.h"

class YouTubeToLink : API{
private:
    std::string getDownloadLinkJson(std::string videoid);

    std::string filename;
    std::string filelength;
    std::string downloadUrl;


public:
    std::string getDownloadLink(std::string videoid);
    std::string getFileName();
};


#endif //QT5PROJECT_YOUTUBETOLINK_H
