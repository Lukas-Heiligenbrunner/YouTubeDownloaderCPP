//
// Created by lukas on 06.04.19.
//

#ifndef QT5PROJECT_API_H
#define QT5PROJECT_API_H


#include <string>

class API {
public:
    std::string request(std::string myurl);

private:
    static size_t write_data(void *contents, size_t size, size_t nmemb, FILE *stream);
};


#endif //QT5PROJECT_API_H
