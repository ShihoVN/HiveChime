#include "bees.h"
#include "ui_bees.h"

#include <QtGui/QMouseEvent>
#include <QtWidgets/QRubberBand>
#include <QtCharts/QChartView>

Bees::Bees(QWidget *parent,DataContainer * tool) :
    QMainWindow(parent),
    ui(new Ui::Bees)
{
    ui->setupUi(this);
    beelog=tool;

    map<int,std::pair<int,int>>intervals=Timetable("Hours");
    for (std::map<int,std::pair<int,int>>::iterator it = intervals.begin();it!=intervals.end();++it) {
        cout<<"X-axis "<<it->second.first<<" Y-axis "<<it->second.second<<endl;
        series->append(it->second.first,it->second.second);
    }
    cout<<"done all "<<endl;

    QPen pen(QRgb(0xFB3640));
    pen.setWidth(4);
    series->setPen(pen);

    map<int,std::pair<int,int>>intervals2=Timetable_exit("Hours");
    for (std::map<int,std::pair<int,int>>::iterator it2 = intervals2.begin();it2!=intervals2.end();++it2) {
        cout<<"X-axis "<<it2->second.first<<" Y-axis "<<it2->second.second<<endl;
        seriesExit->append(it2->second.first,it2->second.second);
    }
    cout<<"done entry "<<endl;

    QPen pen2(QRgb(0xFFF000));
    pen.setWidth(4);
    seriesExit->setPen(pen2);

    map<int,std::pair<int,int>>intervals3=Timetable_enter("Hours");
    for (std::map<int,std::pair<int,int>>::iterator it3 = intervals3.begin();it3!=intervals3.end();++it3) {
        cout<<"X-axis "<<it3->second.first<<" Y-axis "<<it3->second.second<<endl;
        seriesEnter->append(it3->second.first,it3->second.second);
    }
    cout<<"done exit "<<endl;

    QPen pen3(QRgb(0xF00FF));
    pen.setWidth(4);
    seriesEnter->setPen(pen3);


    chart = new Chart();
    chart->addSeries(series);
    chart->addSeries(seriesExit);
    chart->addSeries(seriesEnter);
    chart->setAnimationOptions(QChart::SeriesAnimations);



    QValueAxis *axisX = new QValueAxis;
    QValueAxis *axisY = new QValueAxis;

    axisX->setRange(0, 58);
    axisX->setTickCount(25);
    axisX->setLabelFormat("%.2f");
    axisX->setTitleText("time");
    axisY->setRange(0, 300);
    axisY->setTickCount(20);
    axisY->setTitleText("number of bees");
//    series->attachAxis(axisX);
//    series->attachAxis(axisY);
//    seriesEnter->attachAxis(axisX);
//    seriesEnter->attachAxis(axisY);
//    seriesExit->attachAxis(axisX);
//    seriesExit->attachAxis(axisY);
    QFont font("Times", 40, QFont::Bold);
    chart->setTitleFont(font);
    chart->setTitleBrush(QBrush(Qt::black));
    chart->setTitle("Simple line chart example");

    QLinearGradient plotAreaGradient;
    plotAreaGradient.setStart(QPointF(0, 1));
    plotAreaGradient.setFinalStop(QPointF(1, 0));
    plotAreaGradient.setColorAt(0.0, QRgb(0xDD6E42));
    plotAreaGradient.setColorAt(1.0, QRgb(0xFFC857));
    plotAreaGradient.setCoordinateMode(QGradient::ObjectBoundingMode);
    chart->setPlotAreaBackgroundBrush(plotAreaGradient);
    chart->setPlotAreaBackgroundVisible(true);

//    chart->setAxisX(axisX,series);
//    chart->setAxisY(axisY,series);
    chart->createDefaultAxes();

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->gridLayout->addWidget(chartView);
    //this->setCentralWidget(chartView);
    this->resize(1500, 1000);

    this->grabGesture(Qt::PanGesture);
    this->grabGesture(Qt::PinchGesture);



}


map<int,std::pair<int,int>> Bees::Timetable(string interval){
    Data entre;
    map<int,std::pair<int,int>>timeslots;
    int times = 0;
    int days=0;
    for (unsigned long var = 0; var < beelog->getUdpMessages().size(); ++var) {
        entre=*beelog->getUdpMessages().at(var);
        if(interval.compare("Hours")==0){
            times=std::stoi(entre.time.substr(0,2))+days*24;
            if(timeslots.size()>0 && timeslots.rbegin()->second.first+1>times && timeslots.rbegin()->second.first-1<times ){
                cout<<"times "<<times<<" vs. "<<timeslots.rbegin()->second.first<<endl;
                timeslots.rbegin()->second.second=timeslots.rbegin()->second.second+1;
            }else {
                if(timeslots.size()>0){
                    cout<<"times "<<timeslots.rbegin()->second.first<<" vs.  nob: "<<timeslots.rbegin()->second.second<<endl;
                    if(timeslots.rbegin()->second.first-1>times){
                        days++;
                        times=times+24;
                    }
                }
                timeslots.insert(std::pair<int,std::pair<int,int>>(timeslots.size(),std::pair<int,int>(times,1)));
            }
        }
        //        if(interval.compare("Minutes")==0){
        //            time=std::stoi(entre.time.substr(0,2));
        //            if(timeslots.size()>0)
        //                cout<<"times "<<entre.time<<" vs. "<<timeslots.rbegin()->first<<endl;
        //            if(timeslots.size()>0 && timeslots.rbegin()->first+1>time){
        //                timeslots.rbegin()->second=timeslots.rbegin()->second+1;
        //                cout<<"num of bees "<<timeslots.rbegin()->second<<endl;
        //            }else {
        //                timeslots.insert(std::pair<int,int>(time,1));
        //            }
        //        }
        //        if(interval.compare("seconds")==0){
        //            time=std::stoi(entre.time.substr(0,2));
        //            if(timeslots.size()>0)
        //                cout<<"times "<<entre.time<<" vs. "<<timeslots.rbegin()->first<<endl;
        //            if(timeslots.size()>0 && timeslots.rbegin()->first+1>time){
        //                timeslots.rbegin()->second=timeslots.rbegin()->second+1;
        //                cout<<"num of bees "<<timeslots.rbegin()->second<<endl;
        //            }else {
        //                timeslots.insert(std::pair<int,int>(time,1));
        //            }
        //        }
    }
    cout<<times<<endl;
    return timeslots;
}

map<int,std::pair<int,int>> Bees::Timetable_enter(string interval){
    Data entre;
    map<int,std::pair<int,int>>timeslots;
    int times = 0;
    int days=0;
    for (unsigned long var = 0; var < beelog->getUdpMessages().size(); ++var) {
        entre=*beelog->getUdpMessages().at(var);
        if(entre.type==true){
            entre=*beelog->getUdpMessages().at(var);
            if(interval.compare("Hours")==0){
                times=std::stoi(entre.time.substr(0,2))+days*24;
                if(timeslots.size()>0 && timeslots.rbegin()->second.first+1>times && timeslots.rbegin()->second.first-1<times ){
                    cout<<"times "<<times<<" vs. "<<timeslots.rbegin()->second.first<<endl;
                    timeslots.rbegin()->second.second=timeslots.rbegin()->second.second+1;
                }else {
                    if(timeslots.size()>0){
                        cout<<"times "<<timeslots.rbegin()->second.first<<" vs.  nob: "<<timeslots.rbegin()->second.second<<endl;
                        if(timeslots.rbegin()->second.first-1>times){
                            days++;
                            times=times+24;
                        }
                    }
                    timeslots.insert(std::pair<int,std::pair<int,int>>(timeslots.size(),std::pair<int,int>(times,1)));
                }
            }
            //        if(interval.compare("Minutes")==0){
            //            time=std::stoi(entre.time.substr(0,2));
            //            if(timeslots.size()>0)
            //                cout<<"times "<<entre.time<<" vs. "<<timeslots.rbegin()->first<<endl;
            //            if(timeslots.size()>0 && timeslots.rbegin()->first+1>time){
            //                timeslots.rbegin()->second=timeslots.rbegin()->second+1;
            //                cout<<"num of bees "<<timeslots.rbegin()->second<<endl;
            //            }else {
            //                timeslots.insert(std::pair<int,int>(time,1));
            //            }
            //        }
            //        if(interval.compare("seconds")==0){
            //            time=std::stoi(entre.time.substr(0,2));
            //            if(timeslots.size()>0)
            //                cout<<"times "<<entre.time<<" vs. "<<timeslots.rbegin()->first<<endl;
            //            if(timeslots.size()>0 && timeslots.rbegin()->first+1>time){
            //                timeslots.rbegin()->second=timeslots.rbegin()->second+1;
            //                cout<<"num of bees "<<timeslots.rbegin()->second<<endl;
            //            }else {
            //                timeslots.insert(std::pair<int,int>(time,1));
            //            }
            //        }
        }
    }

    return timeslots;
}
map<int,std::pair<int,int>> Bees::Timetable_exit(string interval){
    Data entre;
    map<int,std::pair<int,int>>timeslots;
    int times = 0;
    int days=0;
    for (unsigned long var = 0; var < beelog->getUdpMessages().size(); ++var) {
        entre=*beelog->getUdpMessages().at(var);
        if(entre.type==false){
            entre=*beelog->getUdpMessages().at(var);
            if(interval.compare("Hours")==0){
                times=std::stoi(entre.time.substr(0,2))+days*24;
                if(timeslots.size()>0 && timeslots.rbegin()->second.first+1>times && timeslots.rbegin()->second.first-1<times ){
                    cout<<"times "<<times<<" vs. "<<timeslots.rbegin()->second.first<<endl;
                    timeslots.rbegin()->second.second=timeslots.rbegin()->second.second+1;
                }else {
                    if(timeslots.size()>0){
                        cout<<"times "<<timeslots.rbegin()->second.first<<" vs.  nob: "<<timeslots.rbegin()->second.second<<endl;
                        if(timeslots.rbegin()->second.first-1>times){
                            days++;
                            times=times+24;
                        }
                    }
                    timeslots.insert(std::pair<int,std::pair<int,int>>(timeslots.size(),std::pair<int,int>(times,1)));
                }
            }
            //        if(interval.compare("Minutes")==0){
            //            time=std::stoi(entre.time.substr(0,2));
            //            if(timeslots.size()>0)
            //                cout<<"times "<<entre.time<<" vs. "<<timeslots.rbegin()->first<<endl;
            //            if(timeslots.size()>0 && timeslots.rbegin()->first+1>time){
            //                timeslots.rbegin()->second=timeslots.rbegin()->second+1;
            //                cout<<"num of bees "<<timeslots.rbegin()->second<<endl;
            //            }else {
            //                timeslots.insert(std::pair<int,int>(time,1));
            //            }
            //        }
            //        if(interval.compare("seconds")==0){
            //            time=std::stoi(entre.time.substr(0,2));
            //            if(timeslots.size()>0)
            //                cout<<"times "<<entre.time<<" vs. "<<timeslots.rbegin()->first<<endl;
            //            if(timeslots.size()>0 && timeslots.rbegin()->first+1>time){
            //                timeslots.rbegin()->second=timeslots.rbegin()->second+1;
            //                cout<<"num of bees "<<timeslots.rbegin()->second<<endl;
            //            }else {
            //                timeslots.insert(std::pair<int,int>(time,1));
            //            }
            //        }
        }
    }
    return timeslots;


}
Bees::~Bees()
{
    delete ui;
}



void Bees::on_upButton_clicked()
{
    chart->scroll(0, 10);
}

void Bees::on_leftButton_clicked()
{
    //chartView->keyPressEvent(QT::Key_Left);
    chart->scroll(-10, 0);
}

void Bees::on_rightButton_clicked()
{
    chart->scroll(10, 0);
}
void Bees::on_downButton_clicked()
{
    chart->scroll(0, -10);
}

void Bees::on_zoomButton_clicked()
{
    chart->zoomIn();
}

void Bees::on_outButton_clicked()
{
    chart->zoomOut();
}
