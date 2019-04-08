//
// Created by lukas on 07.04.19.
//

#ifndef QT5PROJECT_DOWNLOADMANAGER_H
#define QT5PROJECT_DOWNLOADMANAGER_H

#include <functional>

class DownloadManager {
public:
    void downloadUrl(std::string url, std::string filename);

    void onDownloadPercentChange(std::function<void(int percent)> test);
    void onFinishedListener(std::function<void()> test);

    int getPercent();


private:
    static size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream);


    static std::vector<std::function<void(int percent)>> listeners;
    static std::vector<std::function<void()>> finishedlisteners;  //need to be static dont know why

    static void firePercentEvent(int percent);
    void fireFinishedEvent();
    static int loadedsize;
};


#endif //QT5PROJECT_DOWNLOADMANAGER_H
