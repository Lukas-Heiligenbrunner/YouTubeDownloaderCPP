//
// Created by lukas on 07.04.19.
//

#ifndef QT5PROJECT_DOWNLOADMANAGER_H
#define QT5PROJECT_DOWNLOADMANAGER_H

#include <functional>

class DownloadManager {
public:
    //-------------[ Methods ]----------------//

    /**
     * start new Download job
     * @param url download link
     * @param filename filename where to safe to
     */
    void downloadUrl(std::string url, std::string filename);

    /**
     * add new percent changed listener to class
     * @param listener
     */
    void onDownloadPercentChange(std::function<void(double percent)> listener);

    /**
     * add finished event listener to class
     * @param listener
     */
    void onFinishedListener(std::function<void()> test);

    /**
     * get the downloaded percents
     * @return percent value
     */
    double getPercent();

    int getLoadedBytes();
    int getTotalbytes();



private:
    //-------------[ class variables ]----------------//
    static std::vector<std::function<void(double percent)>> listeners;
    static std::vector<std::function<void()>> finishedlisteners;  //need to be static dont know why

    static int loadedsize;
    static int totalfilesize;


    //-------------[ Methods ]----------------//


    static void firePercentEvent(double percent);

    /**
     * fire all finished events
     */
    void fireFinishedEvent();

    //-------------[ Static methods ]----------------//
    /**
     * callback function for CURL
     */
    static size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream);
};


#endif //QT5PROJECT_DOWNLOADMANAGER_H
