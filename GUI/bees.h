#ifndef BEES_H
#define BEES_H
#include <QtCharts/QLineSeries>
#include <QtCharts>

#include <QMainWindow>
//#include "../Data/beegeneration.h"
//#include "../Data/datacontainer.h"
//#include "../Data/datadecoder.h"
#include <iostream>
#include <string>
using namespace  std;
using namespace QtCharts;

namespace Ui {

class Bees;

}

class Bees : public QMainWindow
{
    Q_OBJECT

public:
    explicit Bees(QWidget *parent = nullptr);
    ~Bees();

private:
    Ui::Bees *ui;
    QLineSeries *series = new QLineSeries();
    int genUsr;
};

#endif // BEES_H
