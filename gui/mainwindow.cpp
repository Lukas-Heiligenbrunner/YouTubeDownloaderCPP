#include <iostream>

#include <datatypes/Hashmap.h>

#include <api/API.h>
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
    ui->progressmanual->setValue(0);

    ui->infolabel->setText("currently is nothing to do");
    ui->textfieldname->setText("hangover");

    connect(ui->btndownloadmanul, SIGNAL(clicked()), this, SLOT(startdownloadBtn()));
    connect(this, SIGNAL(setInfoLabelText(QString)), ui->infolabel, SLOT(setText(QString)));
    connect(this, SIGNAL(setProgressBarValue(int)), ui->progressmanual, SLOT(setValue(int)));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::startdownloadBtn() {
    std::cout << "starting downloading\n\n";

    YouTube youtube;
    std::string id = youtube.firstResultID(ui->textfieldname->text().toStdString());
    std::cout << id << " \n";

    YouTubeToLink yttl;
    std::string link = yttl.getDownloadLink(id);
    std::cout << link << " \n";

    DownloadManager manager;

    manager.onDownloadPercentChange([&manager, this](double percent) {
        setProgressBarValue((int) percent);
        std::string infotext;
        infotext = std::to_string(manager.getLoadedBytes()/1024) + " / " + std::to_string(manager.getTotalbytes()/1024) +  " kbytes\n";
        setInfoLabelText(QString::fromStdString(infotext));
    });
    manager.onFinishedListener([this]() {
        ui->infolabel->setText("finished downloading!");
        std::cout << "finished event triggered\n";
    });

    ui->infolabel->setText("downloading");
    manager.downloadUrl(link, yttl.getFileName() + ".mp3");
    std::cout << "finished downloading \n";
}
