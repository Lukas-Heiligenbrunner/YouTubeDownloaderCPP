//
// Created by lukas on 07.04.19.
//

#ifndef QT5PROJECT_YOUTUBETOLINK_H
#define QT5PROJECT_YOUTUBETOLINK_H


#include "API.h"

class YouTubeToLink : API{
private:
    std::string getDownloadLinkJson(std::string videoid);

public:
    std::string getDownloadLink(std::string videoid);
};


#endif //QT5PROJECT_YOUTUBETOLINK_H
