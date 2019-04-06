#include "beegeneration.h"


BeeGeneration::BeeGeneration(int size)
{

    id = "0000";
    generateTime();
    setActivity(size);


}

BeeGeneration::BeeGeneration(string _id, int size){


    id = _id;
    generateTime();
    setActivity(size);
}

BeeGeneration::BeeGeneration(string _id, int size, int time){

    id = _id;
    generateTime(time);
    setActivity(size);
}


void BeeGeneration::setID(string _id, int size){

    id = _id;
    generateTime();
    setActivity(size);

    return;
}


void BeeGeneration::setID(string _id, int size, int time){

    id = _id;
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
    if(current >24){
        time[2] ++;
        time[3] -=24;
        current -= 24;
    }


       while(n == 0){
           current ++;
           std::poisson_distribution<int> poissDistbn(lambda.at(current-1));
           x = poissDistbn(generator);
           n = x;
           if(x == 0){
               time[3]++;
           }
       }

       std::exponential_distribution<double> expDistbn(double(60/x));
       int* next = calculate(60000*expDistbn(generator));
       if(!nextBees.empty()){
            for(int i = 0; i < 6; i ++){
               if(nextBees.top().now[i] < next[i] ){
                   return pairGenerate();

               }
               if(i ==5&& nextBees.top().now[i] == next[i]&&nextBees.top().m < m){
                    return pairGenerate();
               }

            }

       }

       n--;
       return generate(next);



}



string BeeGeneration::pairGenerate(){
    string udp;
    udp = "HC" + id + "-D";
    for(int i = 0; i < 6; i++){
        if(nextBees.top().now[i] < 10){
            udp += "0";
        }
        udp += to_string(nextBees.top().now[i]);

        if(i == 2){
            udp += "T";
        }
        else{
            udp += ".";
        }
    }

    if(nextBees.top().m<100){
        udp += "0";
    }
    if(nextBees.top().m <10){
        udp += "0";
    }
    udp += to_string(m) + "-";


    for(int i =0; i < 10; i++){
        udp+= "B";
        if(i+1 == nextBees.top().board){
            unsigned int s = 1;
            s << (nextBees.top().sensor-1);
            udp += to_string(s);
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

    if(!nextBees.empty()){
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
    }

    return udp;





}

string BeeGeneration::generate(int* next){
    for(int i = 0; i < 6; i++){
        time[i] = next[i];
    }
    milli = m;



    string udp;
    udp = "HC" + id + "-D";
    for(int i = 0; i < 6; i++){
        if(time[i] < 10){
            udp += "0";
        }
        udp += to_string(time[i]);
        if(i == 2){
            udp += "T";
        }
        else{
            udp += ".";
        }
    }
    if(milli<100){
        udp += "0";}
    if(milli <10){
        udp += "0";
    }
    udp+= to_string(milli) + "-";

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


    //HEREEEEE
    for(int i =0; i < 10; i++){
        udp+= "B";
        if(i+1 == board){
            string s = "1";
            for(int i = 1; i < sensor; i++){
                s += "0";
            }
            udp += to_string(btod(s));
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



    //string UDP = udp.substr(0,29);

//    for(int i =0; i < 10; i++){

//        ////HEREEEEE
//        if(i+1 == nextBees.top().board){
//            if(udp.substr(29+(2*board),1) == "0"){
//                    string s = "1";
//                    for(int i = 1; i < nextBees.top().sensor; i++){
//                        s += "0";
//                    }

//                UDP += "B" + to_string(btod(s));
//            }
//            else{

//                unsigned int S= stoi(udp.substr(29+(2*board),1)) ;
//                S += (1 << (nextBees.top().sensor-1));

//            }
//        }
//        else{
//            UDP += udp.substr(28+(2*board),2);
//        }
//    }




//    int udpTime[6];
//    for(int i = 0; i < 6; i++){
//        udpTime[i] = nextBees.top().now[i];
//    }
//    long udpm = nextBees.top().m;
//    nextBees.pop();

//    if(!nextBees.empty()){


//    if(nextBees.top().m == udpm){
//    for(int i = 0; i < 6; i++){
//        if(nextBees.top().now[i] != udpTime[i]){
//            break;
//        }
//        if(i==5){
//            return overGenerate(udp);
//        }
//    }
//    }
//    }

    return udp;
}

int BeeGeneration::findPair(int s){
    switch(s){
    case 1: {return 8; }
    case 2: {return 7; }
    case 3: {return 6; }
    case 4: {return 5; }
    case 5: {return 4; }
    case 6: {return 3; }
    case 7: {return 2; }
    case 8: {return 1; }
    }
    return 0;
}




int* BeeGeneration::calculate(double ms){

    int ntime[6];
    for(int i = 0; i<6; i++){
        ntime[i] = time[i];
    }
    m = milli + ms;


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
            current -=24;
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
    current = 0;



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
    current = _time-1;


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
        int activity = int (size*rate);
        lambda.push_back(activity);
    }
}

int BeeGeneration::btod(string b){
        int num = stoi(b);
        int dec_value = 0;

        int base = 1;

        int temp = num;
        while (temp) {
            int last_digit = temp % 10;
            temp = temp / 10;

            dec_value += last_digit * base;

            base = base * 2;
        }

        return dec_value;
}









