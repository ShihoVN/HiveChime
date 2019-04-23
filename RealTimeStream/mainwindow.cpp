#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * When testing this class, we were unable to test Collins website
 * Becuase "cookies" were disabled we were unable to access
 * the text on the website....need to address this
 *
 * Note: look at website you bookmarked *stream* for the constant
 * receiving of data from a url, need to impliment this
 */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect( manager, &QNetworkAccessManager::finished, this, &MainWindow::downloadFinished);
    const QUrl myurl = QUrl(url);
    QNetworkRequest request(myurl);
    manager->get(request);

}

void MainWindow::downloadFinished(QNetworkReply *reply){
   // QString str;
    QByteArray str;
    str= reply->readAll();
 //  string s=  str.toStdString();

    ui->Label->setText(str); //set URL text to Label



}
