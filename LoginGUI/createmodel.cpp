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
    if((ui->checkBox_3->isChecked() && ui->checkBox_4->isChecked() && ui->checkBox_5->isChecked())||
            (ui->checkBox_3->isChecked() && ui->checkBox_4->isChecked()) || (ui->checkBox_4->isChecked() && ui->checkBox_5)||
            (ui->checkBox_3->isChecked() && ui->checkBox_5->isChecked())){
         QMessageBox::warning(this, tr("ERROR MESSAGE"), tr("Check one box before continuing"));
    }
    else if((ui->lineEdit->text().isEmpty())&& (ui->lineEdit_2->text().isEmpty()) && (ui->lineEdit_3->text().isEmpty())){
         QMessageBox::warning(this, tr("ERROR MESSAGE"), tr("Fill in all Boxes before Continuing"));
    }
    else{
        genModel = new GeneratedModel(this);
        genModel->show();

    }

}



void CreateModel::on_lineEdit_textChanged(const QString &arg1)
{
   QString date1 = arg1;
   date = date1.toStdString();

}

void CreateModel::on_lineEdit_2_textChanged(const QString &arg1)
{
    QString time1 = arg1;
    time = time1.toStdString();
}

void CreateModel::on_lineEdit_3_textChanged(const QString &arg1)
{
    QString duration1 = arg1;
    duration = duration1.toStdString();
}
