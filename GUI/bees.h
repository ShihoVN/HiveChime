#ifndef BEES_H
#define BEES_H

#include <QMainWindow>
//#include "../Data/beegeneration.h"
//#include "../Data/datacontainer.h"
//#include "../Data/datadecoder.h"
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
};

#endif // BEES_H
