#include "createmodel.h"
#include "ui_createmodel.h"
#include <QMessageBox>

CreateModel::CreateModel(QWidget *parent,QString *hivename) :
    QDialog(parent),
    ui(new Ui::CreateModel)
{
    ui->setupUi(this);
    ui->label_9->setText(*hivename);
    date=to_string(ui->dateEdit->date().year())+to_string(
                ui->dateEdit->date().month())+to_string(ui->dateEdit->date().day());
}

CreateModel::~CreateModel()
{
    delete ui;
}

void CreateModel::on_pushButton_clicked()
{
    if((ui->checkBox_3->isChecked() && ui->checkBox_4->isChecked() && ui->checkBox_5->isChecked())||
            (ui->checkBox_3->isChecked() && ui->checkBox_4->isChecked()) || (ui->checkBox_4->isChecked() && ui->checkBox_5->isChecked())||
            (ui->checkBox_3->isChecked() && ui->checkBox_5->isChecked())){
         QMessageBox::warning(this, tr("ERROR MESSAGE"), tr("Check one box before continuing"));
    }
    else if((ui->lineEdit_3->text().isEmpty())){
         QMessageBox::warning(this, tr("ERROR MESSAGE"), tr("Fill in all Boxes before Continuing"));
    }
    else{
        genModel = new GeneratedModel(this,&date,&times,&duration);
        genModel->show();

    }

}

void CreateModel::on_lineEdit_3_textChanged(const QString &arg1)
{
    QString duration1 = arg1;
    duration = duration1.toStdString();
}

void CreateModel::on_dateEdit_dateChanged(const QDate &dates)
{
    date=to_string(dates.day())+to_string(dates.month())+to_string(dates.year());
    cout<<"date: "<<date<<endl;

}

void CreateModel::on_dateEdit_userDateChanged(const QDate &dates)
{
    date=to_string(dates.day())+to_string(dates.month())+to_string(dates.year());
    cout<<"date: "<<date<<endl;

}

void CreateModel::on_timeEdit_userTimeChanged(const QTime &time)
{
    times=to_string(time.hour())+to_string(time.minute());
    cout<<"time: "<<times<<endl;
}

void CreateModel::on_timeEdit_timeChanged(const QTime &time)
{
    times=to_string(time.hour())+to_string(time.minute());
    cout<<"time: "<<times<<endl;
}
