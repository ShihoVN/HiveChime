#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){

    ui->setupUi(this);
    //initalize vector

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(downloadFinished(QNetworkReply*)));
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(on_pushButton_clicked()));
    timer->start(5000); //start timer


    decoder = new DataDecoder(&container);


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




    //Gets the string content from the web page
    QString str;
    str= reply->readAll();
    content = str.toStdString();


    content = readBetween("<body>", "</body>");



    string finalUDP;



    //if there is no message at the time
    if (content.size() > 2 ){


        //splits into udp messages
        vector<string> udps = splitter(content);


        //adds each udp message to vector and to string final udp
        for (unsigned int i = 0; i < udps.size();i++) {
            UDPmessage.push_back(udps.at(i));

            finalUDP += udps.at(i) + "\n";


        }




        //converts final udp to str
        str = QString::fromStdString(finalUDP);


        //changes the label
        ui->Label->setText(str);  //set URL text to Label
        ui->Label->repaint();



        cout << "CONTENT " ;
        cout << ++i;
        cout << "  ";

        cout << content.find('H');
        cout << "  ";

        cout << content.size();

        cout << string("start") + content << endl;


    }





    /*


    str = QString::fromStdString(content);



    ui->Label->setText(str);  //set URL text to Label
    ui->Label->repaint();


    string newstring;
    //udp message will be sperated by return line
    QString qstring;



    //new website with UDp messages
    newstring = readBetween(
                "<body>",
                "</body>"
                );

    cout << "NEW STRINGGGG " + newstring << endl;
  if(newstring != " "){
    vector<string> udps = splitter(newstring, "<br/>");



    for (unsigned int i = 0;i < udps.size();i++) {
        std::cout << udps.at(i) << std::endl;
        decoder->decode(udps.at(i));

        UDPmessage.push_back(udps.at(i));
       qstring = QString::fromStdString(udps.at(i));
       ui->Label->setText(qstring);  //set URL text to Label
       ui->Label->repaint();

    }
    //    std::cout << newstring << std::endl;
    //      decoder->decode(newstring);
    //add UDP message to vector


}

    //printVector(); //print elemetns in the vector




*/
}

string MainWindow::readBetween(string s1, string s2){
    size_t first = content.find(s1) + s1.size();
    size_t second = content.find(s2) - first;
    return content.substr(first, second);
}



vector<string> MainWindow::splitter(string s){
    vector<string> udps;

    udps.push_back(s.substr(s.find('H') ,s.find("<br/>") - s.find('H') ));

    cout << s.substr(s.find('H') ,s.find("<br/>") - s.find('H') );

    cout << " ";


    //if string contains more than 1 udp message
    while (s.find("<br/>")  != string::npos){

        //create a string exempting the previous udp message
        s = s.substr(s.find("<br/>")+ 5, s.length() -1);
        udps.push_back(s.substr(s.find('H') ,s.find("<br/>") - s.find('H') ));
    }








    //    int startIndex = 0;
    //    int  endIndex = 0;
    //    while( (endIndex = s.find(del, startIndex)) < s.size() )
    //    {
    //        std::string val = s.substr(startIndex, endIndex - startIndex);
    //        udps.push_back(val);
    //        startIndex = endIndex + del.size();
    //    }
    //    if(startIndex < s.size())
    //    {
    //        std::string val = s.substr(startIndex);
    //        udps.push_back(val);
    //    }

    return udps;
}









//    cout << "String " << s << endl;

//    vector<string> udps;
//    string newstring = readBetween(
//                "<br/>",
//                "<br/>"
//                );

//    cout << "splitter string " + newstring;
//    udps.push_back(newstring);
//    return udps;





//    cout << "String " << s << endl;
//    cout << "String at 0 " << s.at(1) << endl;
//    while(s.at(0)  == 'H'){

//        unsigned  int index = s.find("<br/>");
//        udps.push_back(s.substr(0,index));
//        cout << "Sub str " << s.substr(0,index) << endl;
//        s = s.substr(index, s.length() -1);
//        cout << "remainder " << s << endl;



//    }


//return udps;


//void MainWindow::printVector(){
//    for(int i =0; i<UDPmessage.size(); i++){
//        cout << UDPmessage.at(i) << endl;
//    }
//}






