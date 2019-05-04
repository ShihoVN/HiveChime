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
    string size;
    string hivemodel;
    if((ui->checkBox_3->isChecked() && ui->checkBox_4->isChecked() && ui->checkBox_5->isChecked())||
            (ui->checkBox_3->isChecked() && ui->checkBox_4->isChecked()) || (ui->checkBox_4->isChecked() && ui->checkBox_5->isChecked())||
            (ui->checkBox_3->isChecked() && ui->checkBox_5->isChecked())){
         QMessageBox::warning(this, tr("ERROR MESSAGE"), tr("Check one box before continuing"));
    }
    else if((ui->lineEdit_3->text().isEmpty())){
         QMessageBox::warning(this, tr("ERROR MESSAGE"), tr("Fill in all Boxes before Continuing"));
    }
    else{
        duration=ui->lineEdit_3->text().toStdString()+ui->comboBox->itemText(0).toStdString();
        cout<<"duration: "<<duration<<endl;
        genModel = new GeneratedModel(this,&hivemodel,&size,&date,&times,&duration);
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
    date=to_string(dates.year()).substr(2,4);
    if(dates.month()<10)
       date=date+ "0"+to_string(dates.month());
    else {
        date=date+ to_string(dates.month());
    }
    if(dates.day()<10)
       date=date+"0"+ to_string(dates.day());
    else {
        date= date+to_string(dates.day());
    }
    cout<<"date: "<<date<<endl;

}

void CreateModel::on_dateEdit_userDateChanged(const QDate &dates)
{
    date=to_string(dates.year()).substr(2,4);
    if(dates.month()<10)
       date=date+ "0"+to_string(dates.month());
    else {
        date=date+ to_string(dates.month());
    }
    if(dates.day()<10)
       date=date+"0"+ to_string(dates.day());
    else {
        date= date+to_string(dates.day());
    }
    cout<<"date: "<<date<<endl;
}

void CreateModel::on_timeEdit_userTimeChanged(const QTime &time)
{
    if(time.hour()<10)
       times="0"+ to_string(time.hour());
    else {
        times= to_string(time.hour());
    }
    if(time.minute()<10)
       times=times+"0"+ to_string(time.minute());
    else {
        times= times+to_string(time.minute());
    }
    cout<<"time: "<<times<<endl;
}

void CreateModel::on_timeEdit_timeChanged(const QTime &time)
{
    if(time.hour()<10)
       times="0"+ to_string(time.hour());
    else {
        times= to_string(time.hour());
    }
    if(time.minute()<10)
       times=times+"0"+ to_string(time.minute());
    else {
        times= times+to_string(time.minute());
    }
    cout<<"time: "<<times<<endl;
}
