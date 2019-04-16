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

    cout << "Hello World!" << endl;
    return 0;
}
