#include <iostream>
#include <api/API.h>
#include <datatypes/Hashmap.h>
#include <api/YouTube.h>
#include <api/YouTubeToLink.h>
#include <download/DownloadManager.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);
    ui->progressmanual->setMaximum(100);
    ui->progressmanual->setMinimum(0);
    ui->progressmanual->setValue(10);


    connect(ui->btndownloadmanul, SIGNAL(clicked()), this, SLOT(startdownloadBtn()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::startdownloadBtn() {
    std::cout << "buttton clicked!\n";
    ui->progressmanual->setValue(ui->progressmanual->value() + 1);
    std::string string = ui->textfieldname->text().toStdString();
    std::cout << string << " <<<  \n\n";
    std::cout << "starting downloading\n\n";

    YouTube youtube;
    std::string id = youtube.firstResultID("fading");
    std::cout << id <<" \n";

    YouTubeToLink yttl;
    std::string link = yttl.getDownloadLink(id);
    std::cout << link <<" \n";

    DownloadManager manager;
    manager.downloadUrl(link);
    std::cout  <<"finished downloading \n";


}
