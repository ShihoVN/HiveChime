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
    hives->add_row_h(0,"HD002","shiho","ShihoMODELDB");
    hives->add_row_h(1,"HD003","Jon","Jon'sMODEL");
    hives->add_row_h(2,"HD004","Basit","BasitMODELDB");

    if(P_rows!=nullptr){
        for(int i =4; i<4*(hives->size()+1);i=i+4){
            added=P_rows[i+1];
            ui->comboBox->addItem(added);
            std::cout <<P_rows[i+1]<< P_rows[i+2]<<P_rows[i+3] << std::endl;
        }
    }
    //call new diaglougue
    introWindow = new Intro();
    introWindow->exec();
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
    secWindowGen->exec();
    std::cout << secWindowGen->realTime <<endl;
    if(secWindowGen->realTime ==true){
        MainWindowAnimate *w = new MainWindowAnimate(this);
            cout << "SEC SOUND "<< secWindowGen->getPlaySound();
        w->setSound(secWindowGen->getPlaySound());
        w->createEnvironment();
        w->show();

    }

   }
   else if(ui->checkBox_2->isChecked()){
       reseacherWindow = new secondWindowResearcher(this,&hiveid);
       reseacherWindow->show();
   }


   //show error message


//    secWindow.setModal(true);
//    secWindow.exec();
 }

}



void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    hiveid=arg1;
    std::cout<<&hiveid<<endl;
}
