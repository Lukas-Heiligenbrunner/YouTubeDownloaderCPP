//
// Created by lukas on 07.04.19.
//

#ifndef QT5PROJECT_YOUTUBE_H
#define QT5PROJECT_YOUTUBE_H


#include "API.h"

class YouTube : API{
public:
    std::string searchYouTube(std::string query);
    std::string firstResultID(std::string keyword);

private:
    static const std::string apikey;
};


#endif //QT5PROJECT_YOUTUBE_H
