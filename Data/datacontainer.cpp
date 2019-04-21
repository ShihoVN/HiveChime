#include "datacontainer.h"

DataContainer::DataContainer()
{
    char** P_rows =beelog->select_table_m();
    Data *added;
    if(P_rows!=nullptr){
        for(int i =6; i<6*(beelog->size()+1);i=i+6){
            added=new Data;
            added->board=std::atoi(P_rows[i+1]);
            added->gate=std::atoi(P_rows[i+2]);
            added->date=P_rows[i+3];
            added->time=P_rows[i+4];
            added->type=P_rows[i+5];
            std::cout <<added->board<< added->gate<<added->date <<added->time << std::endl;
            this->addData(added);
        }
    }
}

DataContainer::DataContainer(string db_name)
{
   beelog=new DBBeeLog(dbtool,db_name);
}

DataContainer::~DataContainer()
{

}

void DataContainer::addData(Data *udpMsg){
    beelog->add_row_m(int(udpMessages.size()),udpMsg->board,to_string(udpMsg->gate),udpMsg->date,to_string(udpMsg->type));
    udpMessages.push_back(udpMsg);

}

vector<Data*> DataContainer:: getUdpMessages(){
    return udpMessages;
}

void DataContainer::track_db(){
    beelog->select_all();
}
