#include <iostream>
#include <api/API.h>
#include <datatypes/Hashmap.h>
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
    std::cout << string << " <<<  \n";
    std::cout << "starting downloading";
    API api;

    Hashmap<std::string,std::string> mymap;
    mymap.add("q","ariana%20grande");
    mymap.add("type","video");
    mymap.add("maxResults","25");
    mymap.add("part","snippet");
    mymap.add("key","AIzaSyAYIXX7lgATXN2xPSCIK71wNQjgUzmYL0s");

    std::cout << api.request("https://www.googleapis.com/youtube/v3/search",false,mymap) << " ------ \n";
    std::cout << "finished \n";
}
