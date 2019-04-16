#ifndef DATACONTAINER_H
#define DATACONTAINER_H
#include <vector>
#include <string>
#include "../Database/dbhivetable.h"
#include "../Database/dbmodeltable.h"
#include "../Database/dbbeelog.h"
#include "../Database/tool.h"

using namespace std;


struct Data{
    string hiveId;
    string date;
    string time;
    int gate; //might be needed-- Lia changed this to an array
    int board; // i think we neeed this - Lia
    bool type; //entry or exit with entry being 1 and exit being 0

};

class DataContainer
{
public:
    DataContainer();
    void addData(Data* d);
    vector<Data*> getUdpMessages();


private:
    Tool* dbtool=new Tool("dbtable");
    DBBeeLog * beelog=new DBBeeLog(dbtool,"dbeelog");
    vector<Data*> udpMessages; //recently inputted data
};

#endif // DATACONTAINER_H
