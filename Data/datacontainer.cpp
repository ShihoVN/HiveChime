#include "datacontainer.h"

DataContainer::DataContainer()
{

}

DataContainer::~DataContainer()
{
}

void DataContainer::addData(Data *udpMsg){
    beelog->add_row_m(udpMessages.size(),udpMsg->board,udpMsg->gate,udpMsg->date,to_string(udpMsg->type));
    udpMessages.push_back(udpMsg);

}

vector<Data*> DataContainer:: getUdpMessages(){
    beelog->select_all();
    return udpMessages;
}
