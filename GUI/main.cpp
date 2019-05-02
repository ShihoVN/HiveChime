#include "bees.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    DataContainer container;
    DataDecoder d(&container);
    BeeGeneration* BG = new BeeGeneration("0002", 400, 15);
    for(int i = 0; i < 1000; i++){
//        if(container.getUdpMessages().size()>10){
//            if(container.getUdpMessages().at(container.getUdpMessages().size()-1)->time>="161050000"){
//                cout << "done"<< endl;
//                break;
//            }
//        }
        d.decode(BG->makeBee());
    }
    QApplication a(argc, argv);
    Bees w(nullptr,&container);
    w.show();

    return a.exec();
}
