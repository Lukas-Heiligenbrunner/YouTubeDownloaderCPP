/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *manualdownload;
    QPushButton *btndownloadmanul;
    QLabel *label;
    QProgressBar *progressmanual;
    QLineEdit *textfieldname;
    QWidget *tab;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(823, 618);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 791, 571));
        manualdownload = new QWidget();
        manualdownload->setObjectName(QStringLiteral("manualdownload"));
        btndownloadmanul = new QPushButton(manualdownload);
        btndownloadmanul->setObjectName(QStringLiteral("btndownloadmanul"));
        btndownloadmanul->setGeometry(QRect(170, 110, 80, 25));
        label = new QLabel(manualdownload);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 40, 171, 17));
        progressmanual = new QProgressBar(manualdownload);
        progressmanual->setObjectName(QStringLiteral("progressmanual"));
        progressmanual->setGeometry(QRect(190, 220, 221, 23));
        progressmanual->setValue(24);
        textfieldname = new QLineEdit(manualdownload);
        textfieldname->setObjectName(QStringLiteral("textfieldname"));
        textfieldname->setGeometry(QRect(90, 70, 151, 25));
        tabWidget->addTab(manualdownload, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        btndownloadmanul->setAccessibleName(QApplication::translate("MainWindow", "btndownloadmanul", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        btndownloadmanul->setText(QApplication::translate("MainWindow", "Download", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Bitte Liednamen eingeben", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(manualdownload), QApplication::translate("MainWindow", "Tab 2", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
