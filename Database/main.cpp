#include <iostream>
#include "tool.h"
#include "dbbeelog.h"
#include "dbhivetable.h"
#include "dbmodeltable.h"
using namespace std;

int main()
{
    Tool* dbtool=new Tool("pla");
    DBHiveTable* dbhove = new  DBHiveTable(dbtool,"Hive1");
    DBModelTable* dbmodel=new DBModelTable(dbtool,"model1");
    DBBeeLog* beelog= new DBBeeLog(dbtool,"beelog");

    dbhove->add_row_h(0,"hive 12","me","model1");
    dbhove->add_row_h(1,"hive 18","me","model1");
    dbhove->add_row_h(2,"hive 10","me","model1");
    dbhove->add_row_h(3,"hive 13","me","model1");
    dbhove->select_all();
    cout << "Hello World!" << endl;
    return 0;
}
