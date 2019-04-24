#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){

    ui->setupUi(this);
    //initalize vector

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(downloadFinished(QNetworkReply*)));
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(on_pushButton_clicked()));
    timer->start(1000); //start timer


}

MainWindow::~MainWindow()
{
    delete ui;
}


//gets data from website
void MainWindow::on_pushButton_clicked()
{

    const QUrl myurl = QUrl(url);
    QNetworkRequest request(myurl);
    request.setRawHeader("User-Agent", "MyOwnBrowser 1.0");

    manager->get(request);

}

void MainWindow::downloadFinished(QNetworkReply *reply){
   if(reply->error()){
       qDebug() << reply->errorString();
       return;
   }

    QString str;
    str= reply->readAll();

    content = str.toStdString();
    string newstring;
    //udp message will be sperated by return line
    QString qstring;
        newstring = readBetween(
            "<body>\r\n",    //
            "\r\n</body>"
        );
     std::cout << newstring << std::endl;
     UDPmessage.push_back(newstring); //add UDP message to vector
     qstring = QString::fromStdString(newstring);
     ui->Label->setText(qstring);  //set URL text to Label
     ui->Label->repaint();



     printVector(); //print elemetns in the vector




}

string MainWindow::readBetween(string s1, string s2){
    size_t first = content.find(s1) + s1.size();
    size_t second = content.find(s2) - first;
    return content.substr(first, second);
}

void MainWindow::printVector(){
    for(int i =0; i<UDPmessage.size(); i++){
        cout << UDPmessage.at(i) << endl;
    }
}



