#include <iostream>
#include "../Data/beegeneration.h"
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;

int main()
{
    int time[6];
    int Ti = 5;
    BeeGeneration *BG = new BeeGeneration("001", 20000, Ti);

    BG->generate();
    float m = BG->getNextM();
    for(int i = 0; i<6;i++){
        time[i] = BG->getNextTime(i);
    }
    auto delta = hours(time[3]) + minutes(time[4]) + seconds(time[5]) + milliseconds((int)m) - hours(Ti);

    std::this_thread::sleep_for(delta);

    cout << BG->makeBee() << endl;



    while(time[3]<10){
        delta = hours(BG->getNextTime(3)) + minutes(BG->getNextTime(4)) + seconds(BG->getNextTime(5)) + milliseconds((int)BG->getNextM());
        delta -= hours(time[3]) - minutes(time[4]) - seconds(time[5]) - milliseconds((int)m);

        std::this_thread::sleep_for(delta);
        cout << BG->makeBee() << endl;


        float m = BG->getNextM();
        for(int i = 0; i<6;i++){
            time[i] = BG->getNextTime(i);
        }


    }




}
