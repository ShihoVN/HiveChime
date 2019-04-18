#include "datacontainer.h"

DataContainer::DataContainer()
{

}

DataContainer::DataContainer(string db_name)
{
    DBBeeLog* beelog=new DBBeeLog(dbtool,db_name);
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
