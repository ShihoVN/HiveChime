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
    while (true){
        auto x = std::chrono::steady_clock::now() + std::chrono::milliseconds(1000);
        do_something(w);
        std::this_thread::sleep_until(x);
    }
}
