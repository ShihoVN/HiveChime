#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include <QMessageBox>

using namespace  std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
 if((!ui->checkBox->isChecked() && !ui->checkBox_2->isChecked()) ||
            (ui->checkBox->isChecked() && ui->checkBox_2->isChecked())){
        QMessageBox::warning(this, tr("ERROR MESSAGE"), tr("Check one box before continuing"));
}else {
   if( ui->checkBox->isChecked()){

    secWindowGen = new secondWindow(this);
    secWindowGen->show();
   }
   else if(ui->checkBox_2->isChecked()){
       reseacherWindow = new secondWindowResearcher(this);
       reseacherWindow->show();
   }


   //show error message


//    secWindow.setModal(true);
//    secWindow.exec();
 }

}


