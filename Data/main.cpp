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
   // d.decode("HC0002-D18.12.19T13.43.16000-B0B1B16B0B0B0B0B0B0B0");

   // d.decode("HC0002-D18.12.19T13.43.16000-B0B1B32B0B0B0B0B0B0B0");
    //d.decode("HC0002-D99.4.1T13.43.16400-B0B0B16B0B0B0B0B0B0B0");
   // d.decode("HC0002-D99.4.1T13.43.16400-B0B0B5B0B0B0B0B0B0B0");



    BeeGeneration* BG = new BeeGeneration("0002", 500);

  for(int i = 0; i < 100; i++){
    //cout << BG->makeBee() << endl;
    d.decode(BG->makeBee());


    for (int i = 0; i < container.getUdpMessages().size(); ++i) {

        cout << "Hive ID: " << container.getUdpMessages().at(i)->hiveId << endl;
        cout << "Date: " << container.getUdpMessages().at(i)->date << endl ;
        cout << "Time: " << container.getUdpMessages().at(i)->time  << endl;
        cout << "Board: " << container.getUdpMessages().at(i)->board  << endl;
        cout << "Gate: " << container.getUdpMessages().at(i)->gate  << endl;
        cout << "Type: " << container.getUdpMessages().at(i)->type << endl ;
        cout << "\n" << endl;

    }
    //container.
  cout << "Size of array in container: " << container.getUdpMessages().size() << endl;

   }




    return 0;
}
