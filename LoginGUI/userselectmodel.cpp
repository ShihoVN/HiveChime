#include "userselectmodel.h"
#include "ui_userselectmodel.h"

userSelectModel::userSelectModel(QWidget *parent,Tool *tool,string *tablename) :
    QDialog(parent),
    ui(new Ui::userSelectModel)
{
    ui->setupUi(this);
    dbtool=tool;
    models=new DBModelTable(tool,*tablename);
    char** P_rows =models->select_table_m();
    QString added;
    if(P_rows!=nullptr){
        for(int i =4; i<4*(models->size()+1);i=i+4){
            added=P_rows[i+1];
            ui->ModelList->addItem(added);
            std::cout <<P_rows[i+1]<< P_rows[i+2]<<P_rows[i+3] << std::endl;
        }
    }
}

userSelectModel::~userSelectModel()
{
    delete ui;
}

void userSelectModel::on_pushButton_clicked()
{
    data=new DataContainer(dbtool,modelname);
    this->hide();
}

void userSelectModel::on_ModelList_itemClicked(QListWidgetItem *item)
{
    modelname=item->text().toStdString();
}
