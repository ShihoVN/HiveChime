#ifndef BEES_H
#define BEES_H
#include <QtCharts/QLineSeries>
#include <QtCharts>

#include <QMainWindow>
#include <iostream>
#include <string>
#include "../Data/beegeneration.h"
#include "../Data/datacontainer.h"
#include "../Data/datadecoder.h"
using namespace  std;
using namespace QtCharts;

namespace Ui {

class Bees;

}

class Bees : public QMainWindow
{
    Q_OBJECT

public:
    explicit Bees(QWidget *parent = nullptr,DataContainer * tool=nullptr);
    map<int,std::pair<int,int>> Timetable(string interval);
    map<int,std::pair<int,int>> Timetable_enter(string interval);

    ~Bees();

private:
    Ui::Bees *ui;
    QLineSeries *series = new QLineSeries();
    DataContainer *beelog;
    int genUsr;
};

#endif // BEES_H
