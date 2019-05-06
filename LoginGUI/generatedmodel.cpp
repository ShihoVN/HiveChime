#include "generatedmodel.h"
#include "ui_generatedmodel.h"


GeneratedModel::GeneratedModel(QWidget *parent , QString *hiveid, string* modelid,string *size, string *date, string *time, string *duration,Tool*tool) :
    QDialog(parent),
    ui(new Ui::GeneratedModel)
{
    ui->setupUi(this);
    dbtool=tool;
    hiveids=hiveid->toStdString();
    modelids=*modelid;
    beelog=new DataContainer(dbtool, *modelid);
    int times=std::stoi(time->substr(0,2));
    BeeGeneration *BG;
    if(*size=="large"){
        BG = new BeeGeneration(hiveid->toStdString(),600,times);
        BG->setDate(std::stoi(date->substr(0,2)),std::stoi(date->substr(2,2)),std::stoi(date->substr(4,5)));
    }
    else if(*size=="medium"){
        BG = new BeeGeneration(hiveid->toStdString(),300,times);
        BG->setDate(std::stoi(date->substr(0,2)),std::stoi(date->substr(2,2)),std::stoi(date->substr(4,5)));
    }
    else{
        BG = new BeeGeneration(hiveid->toStdString(),150,times);
        BG->setDate(std::stoi(date->substr(0,2)),std::stoi(date->substr(2,2)),std::stoi(date->substr(4,5)));
    }
    ui->time_label->setText(time->c_str());
    ui->date_label->setText(date->c_str());
    ui->duration_label->setText(setendDate(*time,*duration).c_str());
    DataDecoder *models=new DataDecoder(beelog);

    for(int i = 0; i < 10000; i++){
        models->decode(BG->makeBee());
    }
}

string GeneratedModel::setendDate(string time,string duration){

    if(duration.substr(1,duration.size()).compare("Hour"))
        return "done";
    if(duration.substr(1,duration.size()).compare("Hour"))
        return "done";

    if(duration.substr(1,duration.size()).compare("Hour"))
        return "done";

    if(duration.substr(1,duration.size()).compare("Hour"))

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

void GeneratedModel::on_pushButton_2_clicked()
{
    DBModelTable* models=new DBModelTable(dbtool,hiveids+"ModelDB");
    char** P_rows =models->select_table_m();
    string added;
    vector<string> modeltitles;
    if(P_rows!=nullptr){
        for(int i =3; i<3*(models->size()+1);i=i+3){
            added=P_rows[i+1];
            modeltitles.push_back(added);
            std::cout <<P_rows[i]<< P_rows[i+1]<<P_rows[i+2] << std::endl;
        }
    }
    models->add_row_m(modeltitles.size(),hiveids+":"+modelids,modelids);
    beelog->storeData();
    beelog->track_db();
    this->hide();
    this->destroy();
}
