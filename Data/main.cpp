#include <iostream>
#include <string>
#include "datadecoder.h"
#include "datacontainer.h"
#include "datagenerator.h"
#include "beegeneration.h"

using namespace std;

int main()
{

    DataDecoder d;
    DataContainer container;
//    d.decode("HC0002-D18.12.19T13.43.16000-B0B1B16B0B0B0B0B0B0B0");

//    d.decode("HC0002-D18.12.19T13.43.16000-B0B1B16B0B0B0B0B0B0B0");
//    d.decode("HC0002-D99.4.1T13.43.16400-B0B0B160B0B0B0B0B0B0B0");
//    d.decode("HC0002-D99.4.1T13.43.16400-B0B0B5B0B0B0B0B0B0B0");


    BeeGeneration* BG = new BeeGeneration("0002", 500);

    for(int i = 0; i < 40; i++){
    cout << BG->makeBee() << endl;
    }
    //d.decode(BG->makeBee());
    //cout << "Here: " << container.getUdpMessages().size() << endl;

//    for (int i = 0; i < container.getUdpMessages().size(); ++i) {
//        cout << "Here: " << endl;

//        cout << "Hive ID: " << container.getUdpMessages().at(i).hiveId;
//        cout << "Date: " << container.getUdpMessages().at(i).date ;
//        cout << "Time: " << container.getUdpMessages().at(i).time ;
//        cout << "Board: " << container.getUdpMessages().at(i).board ;
//        cout << "Gate: " << container.getUdpMessages().at(i).gate ;
//        cout << "Type: " << container.getUdpMessages().at(i).type ;
//    }
    //container.


    //}


    return 0;
}
