#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QMessageBox>


secondWindow::secondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondWindow)
{
    ui->setupUi(this);
}

secondWindow::~secondWindow()
{
    delete ui;
}

void secondWindow::on_pushButton_clicked()
{

    if(ui->checkBox->isChecked() && ui->checkBox_2->isChecked() && ui->checkBox_3->isChecked()||
            ui->checkBox_2->isChecked() && ui->checkBox_3->isChecked() ||
            ui->checkBox->isChecked() && ui->checkBox_3->isChecked()){
        QMessageBox::warning(this, tr("ERROR MESSAGE"), tr("Check one box before continuing"));
    }else{
        if(ui->checkBox_3->isChecked()){
            userSelect = new userSelectModel(this);
            userSelect->show();
        }else if(ui->checkBox->isChecked() && ui->checkBox_2->isChecked()){
            playSound = true;

        }else if(ui->checkBox->isChecked() && !ui->checkBox_2->isChecked()){
            playSound = false;
        }
    }


}

//void secondWindow::playSound(){
//    player = new QMediaPlayer;

//}
