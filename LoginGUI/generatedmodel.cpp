#include "generatedmodel.h"
#include "ui_generatedmodel.h"

GeneratedModel::GeneratedModel(QWidget *parent , string *hiveid, string *size, string *date, string *time, string *duration,string* restraint) :
    QDialog(parent),
    ui(new Ui::GeneratedModel)
{
    ui->setupUi(this);

//    int times=std::stoi(time->substr(0,2));
//    BeeGeneration *BG = new BeeGeneration(*hiveid,15000,times);
//    if(*size=="large"){
//        BG = new BeeGeneration(*hiveid,40000,times);
//        BG->setDate(std::stoi(date->substr(0,2)),std::stoi(date->substr(0,2)),std::stoi(date->substr(0,2)));
//    }
//    else if(*size=="medium"){
//        BG = new BeeGeneration(*hiveid,20000,times);
//    }
//    else{
//        BG = new BeeGeneration(*hiveid,15000,times);
//    }
}

GeneratedModel::~GeneratedModel()
{
    delete ui;
}



void GeneratedModel::on_pushButton_clicked()
{
    delete this;
}
