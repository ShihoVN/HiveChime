#include "createmodel.h"
#include "ui_createmodel.h"

CreateModel::CreateModel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateModel)
{
    ui->setupUi(this);
}

CreateModel::~CreateModel()
{
    delete ui;
}
