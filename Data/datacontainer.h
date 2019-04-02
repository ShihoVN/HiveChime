#ifndef DATACONTAINER_H
#define DATACONTAINER_H
#include <vector>
#include <string>


using namespace std;


struct data{
    string hiveId;
    string date;
    string time;
    int  gate; //might be needed
    bool type; //entry or exit with entry being 1 and exit being 0

};

class DataContainer
{
public:
    DataContainer();

private:
    void addData(data d);



private:

    vector<data> recent;

};

#endif // DATACONTAINER_H
