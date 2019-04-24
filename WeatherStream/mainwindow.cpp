#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){

    parseLocation("New York"); // this needs to be passed in from GUI eventually

    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(findTemp(QNetworkReply*)));
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(getFromWeb()));

    timer->start(1000); //start timer


}

MainWindow::~MainWindow()
{
    delete ui;
}


//gets data from website
void MainWindow::getFromWeb()
{

    const QUrl myurl = QUrl(url);
    QNetworkRequest request(myurl);
    request.setRawHeader("User-Agent", "MyOwnBrowser 1.0");

    manager->get(request);

}

void MainWindow::findTemp(QNetworkReply *reply){
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
//         newstring = readBetween(
//             "span class=\"wob_t\" id=\"wob_tm\" style=\"display:inline\">",
//             "</span><span class=\"wob_t\" id=\"wob_ttm\""
//         );
         newstring = readBetween(
             "<span aria-level=\"3\" role=\"heading\"><div class=\"vk_gy vk_h\" id=\"wob_loc\">New York, NY</div><div class=\"vk_gy vk_sh\" id=\"wob_dts\">Tuesday 11:00 AM</div><div id=\"wob_dcp\"><span class=\"vk_gy vk_sh\" id=\"wob_dc\">Sunny</span></div></span>",
             "<div class=\"vk_gy vk_sh\" id=\"wob_dts\">Tuesday 11:00 AM</div>"
         );
     // std::cout << newstring << std::endl;

      qstring = QString::fromStdString(newstring);
      ui->cityName->setText(qstring);  //set cityName to Label

}

string MainWindow::readBetween(string s1, string s2){
    size_t first = content.find(s1) + s1.size();
    size_t second = content.find(s2) - first;
    //cout <<  content.substr(first, second) << endl;
    return content.substr(first, second);
}

void MainWindow::printVector(){
    for(int i =0; i<UDPmessage.size(); i++){
        cout << UDPmessage.at(i) << endl;
    }
}

void MainWindow::parseLocation(string location){

    string locationURL = string("https://www.google.com/search?q=") +
            string(location) +
            string("+weather&rlz=1C5CHFA_enUS759US761&oq=weather&aqs=chrome.0.69i59j0l3j69i60j0.3427j0j9&sourceid=chrome&ie=UTF-8");
   cout << locationURL <<endl;
   QString qs = QString::fromStdString(locationURL);

   url = qs; //see the url in the header file to this

}




