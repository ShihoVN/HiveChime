#include <iostream>
#include <string>
#include "datadecoder.h"
#include "datacontainer.h"
#include "datagenerator.h"
#include "beegeneration.h"

using namespace std;

int main()
{


    //DataContainer container;
    //DataDecoder d(&container);
    BeeGeneration* BG = new BeeGeneration("0002", 500, 15);

    for(int i = 0; i<50;i++){
        cout << BG->makeBee() << endl;
    }
<<<<<<< HEAD

    container.getUdpMessages();
=======
>>>>>>> 6c8c975bac3e24645df5edec1d5160070132a661

//    for(int i = 0; i < 100; i++){
//        d.decode(BG->makeBee());


//        for (int j = 0; j < container.getUdpMessages().size(); ++j) {

//            cout << "Hive ID: " << container.getUdpMessages().at(j)->hiveId << endl;
//            cout << "Date: " << container.getUdpMessages().at(j)->date << endl ;
//            cout << "Time: " << container.getUdpMessages().at(j)->time  << endl;
//            cout << "Board: " << container.getUdpMessages().at(j)->board  << endl;
//            cout << "Gate: " << container.getUdpMessages().at(j)->gate  << endl;
//            cout << "Type: " << container.getUdpMessages().at(j)->type << endl ;
//            cout << "\n" << endl;
//            cout << "Size of array in container: " << container.getUdpMessages().size() << endl;

//        }
//    }
//    container.track_db();

    return 0;
}
