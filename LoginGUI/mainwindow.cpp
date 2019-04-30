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
    char** P_rows =hives->select_table_h();
    QString added;
    if(P_rows!=nullptr){
        for(int i =4; i<4*(hives->size()+1);i=i+4){
            added=(P_rows[i+1]);
            ui->comboBox->addItem(added);
            std::cout <<P_rows[i+1]<<P_rows[i+2]<<P_rows[i+3] << std::endl;
        }
    }
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


