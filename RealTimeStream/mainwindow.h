#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <string>
#include <QTimer>
#include <iostream>
#include "../Data/datacontainer.h"
#include "../Data/datadecoder.h"
using namespace  std;
//#include <QPixmap> ///to work with images

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    string readBetween(string str1, string str2); //gets string between strings
    //void printVector();
    vector<string> splitter(string s);



private:
    Ui::MainWindow *ui;
    DataContainer container;
    DataDecoder *decoder;
    QNetworkAccessManager *manager;
    QNetworkRequest request;
    QTimer *timer;
    string content; // contains all website information
    QString url = "http://tomcollinsresearch.net/research/rpa/fakeudp/fakeudpmgate.html";

    vector <string> UDPmessage;


   unsigned int i = 0;
private slots:
    void downloadFinished(QNetworkReply *reply);
    void on_pushButton_clicked();

};

#endif // MAINWINDOW_H
