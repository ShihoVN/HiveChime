#include "bees.h"
#include "ui_bees.h"
Bees::Bees(QWidget *parent,DataContainer * tool) :
    QMainWindow(parent),
    ui(new Ui::Bees)
{
    ui->setupUi(this);
    beelog=tool;
    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);

    QChart *chart = new QChart();
    chart->addSeries(series);
    QValueAxis *axisX = new QValueAxis;
    QValueAxis *axisY = new QValueAxis;

    axisX->setRange(1, 10);
    axisX->setTickCount(10);
    axisX->setLabelFormat("%.2f");
    axisX->setTitleText("time");
    axisY->setTitleText("number of bees");

    chart->setTitle("Simple line chart example");
    chart->setAxisX(axisX,series);
    chart->setAxisY(axisY,series);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    this->setCentralWidget(chartView);
    this->resize(600, 500);
    Timetable("Hours");
}
void Bees::Timetable(string interval){
    Data entre;
    map<int,int>timeslots;
    int time = 0;
    for (unsigned long var = 0; var < beelog->getUdpMessages().size(); ++var) {
        entre=*beelog->getUdpMessages().at(var);
        if(interval.compare("Hours")==0){
            time=std::stoi(entre.time.substr(0,2));
            if(timeslots.size()>0)
                cout<<"times "<<entre.time<<" vs. "<<timeslots.rbegin()->first<<endl;
            if(timeslots.size()>0 && timeslots.rbegin()->first+1>time){
                timeslots.rbegin()->second=timeslots.rbegin()->second+1;
                cout<<"num of bees "<<timeslots.rbegin()->second<<endl;
            }else {
                timeslots.insert(std::pair<int,int>(time,1));
            }
        }
    }
    cout<<time<<endl;
}
Bees::~Bees()
{
    delete ui;
}
