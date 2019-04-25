#ifndef DATACONTAINER_H
#define DATACONTAINER_H
#include <vector>
#include <string>
#include "../Database/dbbeelog.h"
#include "../Database/tool.h"
#include "../Database/dbtable.h"
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
    DataContainer(string db_name);
    ~DataContainer();
    void addData(Data* d);
    void loadData(Data* d);
    vector<Data*> getUdpMessages();
    void track_db();

private:
    Tool *dbtool=new Tool("dbtable");
    DBBeeLog *bee_logdb=new DBBeeLog(dbtool,"BEELOG");
    vector<Data*> udpMessages; //recently inputted data

};

#endif // DATACONTAINER_H
