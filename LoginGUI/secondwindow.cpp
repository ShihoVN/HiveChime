#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QMessageBox>


secondWindow::secondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondWindow)
{
    mainWindow = parent;

    ui->setupUi(this);
}

secondWindow::~secondWindow()
{
    mainWindow->show();
    delete ui;
}

void secondWindow::on_pushButton_clicked()
{

    if(ui->checkBox->isChecked() && ui->checkBox_2->isChecked() && ui->checkBox_3->isChecked()||
            ui->checkBox_2->isChecked() && ui->checkBox_3->isChecked() ||
            ui->checkBox->isChecked() && ui->checkBox_3->isChecked()){
        QMessageBox::warning(this, tr("ERROR MESSAGE"), tr("Check one box before continuing"));
    }
    else{
        if(ui->checkBox_3->isChecked()){
            // userSelect = new userSelectModel(this);
            //userSelect->show();
            viewModel = true;
            this->hide();
        }else if(ui->checkBox->isChecked() && ui->checkBox_2->isChecked()){
            // animateW->show();
            playSound = true;
            realTime = true;
            this->hide();


        }else if(ui->checkBox->isChecked() && !ui->checkBox_2->isChecked()){
            playSound = false;
            realTime = true;
            this->hide();
        }else if(ui->checkBox_4->isChecked()){

        }
    }



}

bool secondWindow::getPlaySound(){
    return playSound;
}


