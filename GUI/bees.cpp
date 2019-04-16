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
