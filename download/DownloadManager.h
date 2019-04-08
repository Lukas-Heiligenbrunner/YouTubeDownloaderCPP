//
// Created by lukas on 07.04.19.
//

#ifndef QT5PROJECT_DOWNLOADMANAGER_H
#define QT5PROJECT_DOWNLOADMANAGER_H

#include <functional>

class DownloadManager {
public:
    void downloadUrl(std::string url, std::string filename);

    void addActionListener(std::function<void()> test);

    int getPercent();


private:
    static size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream);

    static void fireEvent();
    static std::vector<std::function<void()>> listeners;
    static int loadedsize;
};


#endif //QT5PROJECT_DOWNLOADMANAGER_H
