#ifndef DATACONTAINER_H
#define DATACONTAINER_H
#include <vector>
#include <string>


using namespace std;


struct data{
    string hiveId;
    string date;
    string time;
    int  gate;//might be needed
    int type;//entry or exit with entry being 0 and exit being 1

};

class DataContainer
{
public:
    DataContainer();
    void addData(data d);

private:

    vector<data> recent;

};

#endif // DATACONTAINER_H
