#include "bees.h"
#include "ui_bees.h"
Bees::Bees(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Bees)
{
    ui->setupUi(this);
//    series->setPointLabelsVisible(true);    // is false by default
//    series->setPointLabelsColor(Qt::black);
//    series->setPointLabelsFormat("@yPoint");
    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);

    QChart *chart = new QChart();
    //chart->legend()->hide();
    //chart->legend().
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
    this->resize(400, 300);


}

Bees::~Bees()
{
    delete ui;
}
