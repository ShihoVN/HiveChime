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
<<<<<<< HEAD

private:

=======
    void addData(data d);

private:

    vector<data> recent;

>>>>>>> 6eca62e335773e3ac299a6eb43865de0daf8dec6
};

#endif // DATACONTAINER_H
