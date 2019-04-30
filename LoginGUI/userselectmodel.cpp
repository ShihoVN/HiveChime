#include "userselectmodel.h"
#include "ui_userselectmodel.h"

userSelectModel::userSelectModel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userSelectModel)
{
    ui->setupUi(this);
}

userSelectModel::~userSelectModel()
{
    delete ui;
}
