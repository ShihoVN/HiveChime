#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <string>
#include <iostream>
using namespace  std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString url = "https://text.npr.org";
    //QString url = "http://tomcollinsresearch.net/research/rpa/hworld/numbers.html";
private slots:
    void downloadFinished(QNetworkReply*);
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
