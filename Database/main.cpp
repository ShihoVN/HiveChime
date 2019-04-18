#include <iostream>
#include "tool.h"
#include "dbhivetable.h"
#include "dbbeelog.h"
#include "dbmodeltable.h"
using namespace std;

int main()
{
    Tool* dbtool = new Tool("dbtable");
    DBHiveTable *hivedb=new DBHiveTable(dbtool,"HIVEDB");
    DBModelTable *modeldb=new DBModelTable(dbtool,"MODELDB");
    DBBeeLog *bee_logdb=new DBBeeLog(dbtool,"BEELOG");

   hivedb->add_row_h(0,"HD002","shiho","MODELDB");
   modeldb->add_row_m(0,"storing bees","BEELOG");
   bee_logdb->add_row_m(0,1,"A","07/21/1111","exit");

hivedb->select_all();
modeldb->select_all();
bee_logdb->select_all();
   return 0;
}
