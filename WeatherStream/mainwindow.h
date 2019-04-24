#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <string>
#include <QTimer>
#include <iostream>
#include <sstream>
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
    void printVector();

    void parseLocation(string location); // return the url with correct location





private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;
    QNetworkRequest request;
    QTimer *timer;
    string content; // contains all website information
    QString url;


    vector <string> UDPmessage;
private slots:
   void getFromWeb();
   void findTemp(QNetworkReply *reply);


};

#endif // MAINWINDOW_H
