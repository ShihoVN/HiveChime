#include <iostream>
#include <string>
#include "datadecoder.h"
#include "datacontainer.h"
#include "datagenerator.h"
#include "beegeneration.h"

using namespace std;

int main()
{
    DataContainer container;
        DataDecoder d(&container);
        BeeGeneration* BG = new BeeGeneration("0002", 500);

    for(int i = 0; i < 100; i++){
        d.decode(BG->makeBee());

    }
    container.getUdpMessages();

//        for (int i = 0; i < container.getUdpMessages().size(); ++i) {

//            cout << "Hive ID: " << .at(i)->hiveId << endl;
//            cout << "Date: " << container.getUdpMessages().at(i)->date << endl ;
//            cout << "Time: " << container.getUdpMessages().at(i)->time  << endl;
//            cout << "Board: " << container.getUdpMessages().at(i)->board  << endl;
//            cout << "Gate: " << container.getUdpMessages().at(i)->gate  << endl;
//            cout << "Type: " << container.getUdpMessages().at(i)->type << endl ;
//            cout << "\n" << endl;

//        cout << "Size of array in container: " << container.getUdpMessages().size() << endl;

//    }
}
