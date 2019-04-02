#include "beegeneration.h"


BeeGeneration::BeeGeneration(string filename)
{
    ifstream myfile(filename);

    int line;
    if(myfile.is_open()){
        while(!myfile.eof()){
            myfile >> line;
            lambda.push_back(line);
        }
    }
    else{
        cerr << "error" << endl;
    }
    myfile.close();
    id = "0000";
    current = 0;
    generateTime();
}

BeeGeneration::BeeGeneration(string iD1, string filename){
    ifstream myfile(filename);

    int line;
    if(myfile.is_open()){
        while(!myfile.eof()){
            myfile >> line;
            lambda.push_back(line);
        }
    }
    else{
        cerr << "error" << endl;
    }
    myfile.close();
    id = iD1;
    current = 0;
    generateTime();
}

void BeeGeneration::setID(string iD1){
    id = iD1;
    generateTime();
    return;
}
void BeeGeneration::setID(string iD1, string filename){
    ifstream myfile(filename);

    int line;
    if(myfile.is_open()){
        while(!myfile.eof()){
            myfile >> line;
            lambda.push_back(line);
        }
    }
    else{
        cerr << "error" << endl;
    }
    myfile.close();

    id = iD1;
    generateTime();

    return;
}


BeeGeneration::~BeeGeneration()
{

}

string BeeGeneration::makeBee()
{
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

    //VERY SIMPLE
    int b1 = rand() % 10 +1;
    int b2 = rand() % 10 +1;
    int s1 = rand() % 8 + 4;
    int s2 = rand() % 4 + 1;
    unsigned int S1 = 1;
    S1<< s1;
    unsigned int S2 = 1;
    S2 << s2;


    for(int i=0; i < 10; i++){
        udp += "B";
        if((i+1)== b1){
            udp+= S1;
        }
        if((i+1) == b2){
            udp += S2;
        }
        else{
            udp += "0";
        }
    }



//    //std::binomial_distribution<int, double> binom(5, 1.0/6.0);


       if(n == 0){
           std::poisson_distribution<int> poissDistbn(lambda.at(current));
            n = poissDistbn(generator);
       }
       else{
           n--;
       }
       std::gamma_distribution<double> gamma(lambda.at(current));
       add(gamma(generator));

       return udp;


}

void BeeGeneration::add(long ms){
    milli +=ms;
    while(milli > 1000){
        milli -1000;
        time[5]++;
        while(time[5] >60){
            time[5]-=60;
            time[4] ++;
        }
        if(time[4] >60){
            time[4]-=60;
            time[3]++;
        }
        if(time[3]>24){
            time[3]-=24;
            time[2]++;
        }
        if(time[2]>28){
            if(time[1]==2){
                time[2]-=28;
                time[1]++;
            }
            if(time[2]>30){
                if(time[1]==4 ||time[1]==6||time[1]==9||time[1]==11){
                    time[2]-=30;
                    time[1]++;
                }
            }
            if(time[2] > 31){
                time[2]-=31;
                time[1]++;
            }
        }
        if(time[1]>12){
            time[1]-=12;
            time[0]++;
        }
    }

}

void BeeGeneration::generateTime(){
    time[0] = rand() % 100;
    time[1] = rand() % 12 + 1;
    time[2] = rand() % 29 + 1;

    time[3] = rand() % 24;
    time[4] = rand() % 60;
    time[5] = rand() % 60;

    milli = rand() % 1000;


    //set a time;
}
