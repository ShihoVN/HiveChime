#include "weather.h"
#include <QApplication>

void do_something(Weather* w){
    w->cleanUpForMove();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Weather *w = new Weather();
    w->show();
    int i=0;
    while (true){
        auto x = std::chrono::steady_clock::now() +std::chrono::milliseconds(100);
        do_something(w);
        qApp->processEvents();
        std::this_thread::sleep_until(x);
        i++;
    }
   // return a.exec();
}
