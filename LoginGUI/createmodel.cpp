#include "createmodel.h"
#include "ui_createmodel.h"
#include <QMessageBox>

CreateModel::CreateModel(QWidget *parent,QString *hivename) :
    QDialog(parent),
    ui(new Ui::CreateModel)
{
    ui->setupUi(this);
    ui->label_9->setText(*hivename);
}

CreateModel::~CreateModel()
{
    delete ui;
}

void CreateModel::on_pushButton_clicked()
{
    if(ui->checkBox_3->isChecked() && ui->checkBox_4->isChecked() && ui->checkBox_5->isChecked()||
            ui->checkBox_3->isChecked() && ui->checkBox_4->isChecked() || ui->checkBox_4->isChecked() && ui->checkBox_5||
            ui->checkBox_3->isChecked() && ui->checkBox_5->isChecked()){
         QMessageBox::warning(this, tr("ERROR MESSAGE"), tr("Check one box before continuing"));
    }
}
