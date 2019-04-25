#include "bees.h"
#include "ui_bees.h"

Bees::Bees(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Bees)
{
    ui->setupUi(this);
}

Bees::~Bees()
{
    delete ui;
}

void Bees::on_checkBox_stateChanged(int arg1)
{
    genUsr = arg1;
    std::cout<< arg1<< endl;
}
