#include "datacontainer.h"

DataContainer::DataContainer()
{

}

void DataContainer::addData(Data udpMsg){
    udpMessages.push_back(udpMsg);

}

vector<Data> DataContainer:: getUdpMessages(){
    return udpMessages;
}
