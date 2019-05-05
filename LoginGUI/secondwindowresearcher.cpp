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

    if((!ui->checkBox_2->isChecked() && !ui->checkBox_3->isChecked()) && !ui->checkBox_4->isChecked() && !ui->checkBox_5->isChecked()){
        QMessageBox::warning(this, tr("ERROR MESSAGE"), tr("Check one box before continuing"));
    }
    else{

        if(ui->checkBox_2->isChecked()){
            // animateW->show();
            //playSound = true;
            realTime = true;
            this->hide();
            //this->destroy();
        }
        else if(ui->checkBox_5->isChecked()){
            rawData = true;
            this->hide();
        }else if(ui->checkBox_4->isChecked()){
            createModel = true;
            this->hide();
        }
    }
    cout << "Realt time " << realTime << endl;

}

bool secondWindowResearcher::getPlaySound(){
    return playSound;
}
