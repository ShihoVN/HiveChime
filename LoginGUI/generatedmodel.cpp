#include "generatedmodel.h"
#include "ui_generatedmodel.h"

GeneratedModel::GeneratedModel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GeneratedModel)
{
    ui->setupUi(this);
}

GeneratedModel::~GeneratedModel()
{
    delete ui;
}



void GeneratedModel::on_pushButton_clicked()
{
    delete this;
}
