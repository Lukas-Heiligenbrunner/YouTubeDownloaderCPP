//
// Created by lukas on 06.04.19.
//

#ifndef QT5PROJECT_API_H
#define QT5PROJECT_API_H


#include <string>
#include <datatypes/Hashmap.h>

class API {
protected:
    std::string request(std::string myurl);
    std::string request(std::string myurl, bool post, Hashmap<std::string,std::string> &map);

private:
    static size_t write_data(void *buffer, size_t size, size_t buffersize, FILE *stream);
};


#endif //QT5PROJECT_API_H
