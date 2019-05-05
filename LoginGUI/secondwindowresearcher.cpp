#include "secondwindowresearcher.h"
#include "ui_secondwindowresearcher.h"
#include <QMessageBox>

secondWindowResearcher::secondWindowResearcher(QWidget *parent,QString *hivename) :
    QDialog(parent),
    ui(new Ui::secondWindowResearcher)
{
    ui->setupUi(this);
    ui->label->setText(*hivename);
}

secondWindowResearcher::~secondWindowResearcher()
{
    delete ui;
}

void secondWindowResearcher::on_pushButton_clicked()
{
    QString Hiveid=ui->label->text();

    if((!ui->checkBox->isChecked() && !ui->checkBox_2->isChecked()) && !ui->checkBox_3->isChecked() && !ui->checkBox_4->isChecked() && !ui->checkBox_5->isChecked()){
        QMessageBox::warning(this, tr("ERROR MESSAGE"), tr("Check one box before continuing"));
    }
    if(ui->checkBox_4->isChecked()){
        modelWindow = new CreateModel(this,&Hiveid);
        modelWindow->show();
    }
    else if(ui->checkBox->isChecked() && ui->checkBox_2->isChecked()){
        // animateW->show();
        playSound = true;
        realTime = true;
        this->hide();


    }else if(ui->checkBox->isChecked() && !ui->checkBox_2->isChecked()){
        playSound = false;
        realTime = true;
        this->hide();
    }else if(ui->checkBox_5->isChecked()){
        realTimeData = new MainWindowRT();
        realTimeData->show();
    }

}
