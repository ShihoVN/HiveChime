#include "generatedmodel.h"
#include "ui_generatedmodel.h"

GeneratedModel::GeneratedModel(QWidget *parent , string *hiveid, string *size, string *date, string *time, string *duration,Tool*dbtool) :
    QDialog(parent),
    ui(new Ui::GeneratedModel)
{
    ui->setupUi(this);
    cout<<"hiveid: "<<*hiveid<<endl;
    beelog=new DataContainer(dbtool,*hiveid);
    int times=std::stoi(time->substr(0,2));
    cout<<"times: "<<times<<endl;
    BeeGeneration *BG = new BeeGeneration(*hiveid,15000,times);
    if(*size=="large"){
        BG = new BeeGeneration(*hiveid,40000,times);
        BG->setDate(std::stoi(date->substr(0,2)),std::stoi(date->substr(2,2)),std::stoi(date->substr(4,5)));
    }
    else if(*size=="medium"){
        BG = new BeeGeneration(*hiveid,20000,times);
        BG->setDate(std::stoi(date->substr(0,2)),std::stoi(date->substr(2,2)),std::stoi(date->substr(4,5)));
    }
    else{
        BG = new BeeGeneration(*hiveid,15000,times);
        BG->setDate(std::stoi(date->substr(0,2)),std::stoi(date->substr(2,2)),std::stoi(date->substr(4,5)));
    }
    ui->time_label->setText(time->c_str());
    ui->date_label->setText(date->c_str());
    ui->duration_label->setText(setendDate().c_str());
    DataDecoder *models=new DataDecoder(beelog);

    for(int i = 0; i < 10000; i++){
        models->decode(BG->makeBee());
    }
    beelog->storeData();
}

string GeneratedModel::setendDate(){
    return "done";
}

GeneratedModel::~GeneratedModel()
{
    delete ui;
}



void GeneratedModel::on_pushButton_clicked()
{
    delete this;
}
