#include "bees.h"
#include "ui_bees.h"
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
    //    series->append(0, 6);
    //    series->append(2, 4);
    //    series->append(3, 8);
    //    series->append(7, 4);
    //    series->append(10, 5);

    QChart *chart = new QChart();
    chart->addSeries(series);
    QValueAxis *axisX = new QValueAxis;
    QValueAxis *axisY = new QValueAxis;

    axisX->setRange(0, 58);
    axisX->setTickCount(25);
    axisX->setLabelFormat("%.2f");
    axisX->setTitleText("time");
    axisY->setRange(0, 300);
    axisY->setTickCount(20);
    axisY->setTitleText("number of bees");

    chart->setTitle("Simple line chart example");
    chart->setAxisX(axisX,series);
    chart->setAxisY(axisY,series);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    this->setCentralWidget(chartView);
    this->resize(1500, 1000);
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
    cout<<times<<endl;
    return timeslots;
}
Bees::~Bees()
{
    delete ui;
}
