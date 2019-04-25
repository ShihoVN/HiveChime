#ifndef BEES_H
#define BEES_H

#include <QMainWindow>
//#include "../Data/beegeneration.h"
//#include "../Data/datacontainer.h"
//#include "../Data/datadecoder.h"
#include <iostream>
#include <string>
using namespace  std;
namespace Ui {

    class Bees;

}

class Bees : public QMainWindow
{
    Q_OBJECT

public:
    explicit Bees(QWidget *parent = nullptr);
    ~Bees();

private slots:
    void on_checkBox_stateChanged(int arg1);

private:
    Ui::Bees *ui;
    int genUsr;
};

#endif // BEES_H
