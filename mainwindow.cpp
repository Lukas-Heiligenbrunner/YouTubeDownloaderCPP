#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->progressmanual->setMaximum(100);
    ui->progressmanual->setMinimum(0);
    ui->progressmanual->setValue(10);


    connect (ui->btndownloadmanul, SIGNAL( clicked() ), this, SLOT( btnclick() ));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::btnclick() {
        std::cout << "buttton clicked!\n";
        ui->progressmanual->setValue(ui->progressmanual->value()+1);
        std::string string = ui->textfieldname->text().toStdString();
        std::cout << string << " <<<  \n";
}
