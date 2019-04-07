//
// Created by lukas on 07.04.19.
//

#ifndef QT5PROJECT_DOWNLOADMANAGER_H
#define QT5PROJECT_DOWNLOADMANAGER_H


class DownloadManager {
public:
    void downloadUrl(std::string url);

private:
    static size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream);

    static int loadedsize;
};


#endif //QT5PROJECT_DOWNLOADMANAGER_H
