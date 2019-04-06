#include "beegeneration.h"


BeeGeneration::BeeGeneration(int size)
{

    id = "0000";
    current = 0;
    generateTime();
    setActivity(size);


}

BeeGeneration::BeeGeneration(string _id, int size){


    id = _id;
    current = 0;
    generateTime();
    setActivity(size);
}

BeeGeneration::BeeGeneration(string _id, int size, int time){

    id = _id;
    current = time;
    generateTime(time);
    setActivity(size);
}


void BeeGeneration::setID(string _id, int size){

    id = _id;
    current = 0;
    generateTime();
    setActivity(size);

    return;
}


void BeeGeneration::setID(string _id, int size, int time){

    id = _id;
    current = time;
    generateTime(time);
    setActivity(size);

    return;
}


BeeGeneration::~BeeGeneration()
{

}

string BeeGeneration::makeBee()
{


//    //std::binomial_distribution<int, double> binom(5, 1.0/6.0);


       if(n == 0){
           std::poisson_distribution<int> poissDistbn(lambda.at(current));
           x = poissDistbn(generator);
           n = x;
       }

       std::binomial_distribution<long> expDistbn(3600000/x);
       int* next = calculate(expDistbn(generator));
       for(int i = 0; i < 6; i ++){
           if(nextBees.top().now[i] < next[i] ){
               return pairGenerate();
           }

       }
       return generate();



}

string BeeGeneration::pairGenerate(){
    string udp;
    udp = "HC" + id + "-D";
    for(int i = 0; i < 6; i++){
        if(nextBees.top().now[i] < 10){
            udp += "0";
        }
        udp += nextBees.top().now[i];

        if(i = 2){
            udp += "T";
        }
        else{
            udp += ".";
        }
    }
    if(nextBees.top().m<100){
        udp += "0";
    }if(nextBees.top().m <10){
        udp += "0";
    }
    udp+= m + "-";


    for(int i =0; i < 10; i++){
        udp+= "B";
        if(i+1 == nextBees.top().board){
            unsigned int s = 1;
            s << nextBees.top().sensor;
            udp += s;
        }
        else{
            udp += "0";
        }
    }

    int udpTime[6];
    for(int i = 0; i < 6; i++){
        udpTime[i] = nextBees.top().now[i];
    }
    long udpm = nextBees.top().m;

    nextBees.pop();

    if(nextBees.top().m == udpm){
    for(int i = 0; i < 6; i++){
        if(nextBees.top().now[i] != udpTime[i]){
            break;
        }
        if(i==5){
            return overGenerate(udp);
        }
    }
    }

    return udp;





}

string BeeGeneration::generate(){
    string udp;
    udp = "HC" + id + "-D";
    for(int i = 0; i < 6; i++){
        if(time[i] < 10){
            udp += "0";
        }
        udp += time[i];

        if(i = 2){
            udp += "T";
        }
        else{
            udp += ".";
        }
    }
    if(milli<100){
        udp += "0";
    }if(milli <10){
        udp += "0";
    }
    udp+= milli + "-";

    //FIX THIS
    nextBee pairBee;
    int board = rand() % 10+1;
    pairBee.board = board;

    int sensor = rand() % 8+1;
    pairBee.sensor = findPair(sensor);

    std::poisson_distribution<int> poissDistbn(490);
    int* elpst =  calculate(poissDistbn(generator));
    pairBee.m = m;
    for(int i = 0; i < 6; i++){
        pairBee.now[i] = elpst[i];
    }

    nextBees.push(pairBee);

    for(int i =0; i < 10; i++){
        udp+= "B";
        if(i+1 == board){
            unsigned int s = 1;
            s << sensor;
            udp += s;
        }
        else{
            udp += "0";
        }
    }

    if(nextBees.top().m != milli){
        return udp;
    }
    for(int i = 0; i < 6; i++){
        if(nextBees.top().now[i] != time[i]){
            break;
        }
        if(i==5){
            return overGenerate(udp);
        }
    }

    return udp;

}

string BeeGeneration::overGenerate(string udp){
    int sensor = nextBees.top().sensor;
    int board = nextBees.top().board;
    for(int i =0; i < 10; i++){
        udp+= "B";
        if(i+1 == board){
            unsigned int s = 1;
            s << sensor;
            udp += s;
        }
        else{
            udp += "0";
        }
    }
    nextBees.pop();

    int udpTime[6];
    for(int i = 0; i < 6; i++){
        udpTime[i] = nextBees.top().now[i];
    }
    long udpm = nextBees.top().m;

    nextBees.pop();

    if(nextBees.top().m == udpm){
    for(int i = 0; i < 6; i++){
        if(nextBees.top().now[i] != udpTime[i]){
            break;
        }
        if(i==5){
            return overGenerate(udp);
        }
    }
    }

    return udp;
}

int BeeGeneration::findPair(int s){
    switch(s){
    case 1: return 8;
    case 2: return 7;
    case 3: return 6;
    case 4: return 5;
    case 5: return 4;
    case 6: return 3;
    case 7: return 2;
    case 8: return 1;
    }
}




int* BeeGeneration::calculate(long ms){
    int ntime[6];
    for(int i = 0; i<6; i++){
        time[i] = ntime[i];
    }

    m = milli +ms;
    while(m > 1000){
        m -=1000;
        ntime[5]++;
        while(ntime[5] >60){
            ntime[5]-=60;
            ntime[4] ++;
        }
        if(ntime[4] >60){
            ntime[4]-=60;
            ntime[3]++;
        }
        if(ntime[3]>24){
            ntime[3]-=24;
            ntime[2]++;
        }
        if(ntime[2]>28){
            if(ntime[1]==2){
                ntime[2]-=28;
                ntime[1]++;
            }
            else if(ntime[2]>30){
                if(ntime[1]==4 ||ntime[1]==6||ntime[1]==9||ntime[1]==11){
                    ntime[2]-=30;
                    ntime[1]++;
                }
            }
            if(ntime[2] > 31){
                ntime[2]-=31;
                ntime[1]++;
            }
        }
        if(ntime[1]>12){
            ntime[1]-=12;
            ntime[0]++;
        }
    }

    return ntime;

}

void BeeGeneration::generateTime(){

    time[0] = 19;
    time[1] = 1;
    time[2] = 1;

    time[3] = 0;
    time[4] = 0;
    time[5] = 0;

    milli = 0;
    n = 0;

    return;

}

void BeeGeneration::generateTime(int _time){

    time[0] = 19;
    time[1] = 1;
    time[2] = 1;

    time[3] = _time;
    time[4] = 0;
    time[5] = 0;

    milli = 0;
    n = 0;

    return;
}

void BeeGeneration::setActivity(int size){
    double rate = 0;
    for(int i = 0; i<24 ; i++){
        if(i <5){
            rate = 0;
        }
        else if(i == 5){
            rate = 0.1;
        }
        else if(i>5){
            rate += 0.05;
        }
        else if(i>9){
            rate += 0.1;
        }
        else if(i>11 && i <15){
            rate = 0.55;
        }
        else if(i == 15){
            rate = 0.35;
        }
        else if(i == 16){
            rate -= 0.1;
        }
        else if(i == 17){
            rate = 0.3;
        }
        else if(i >17 && i <21){
            rate -= 0.1;
        }
        else{
            rate = 0;
        }

        lambda.push_back(size*rate);
    }
}








