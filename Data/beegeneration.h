#ifndef BEEGENERATION_H
#define BEEGENERATION_H
#include <string>
#include <iostream>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <vector>
#include <fstream>
#include <thread>
#include <functional>
#include <cstring>
#include <fstream>
#include <iostream>
#include <time.h>
#include <queue>
#include <string.h>




using namespace std;

struct nextBee{
    int now[6];
    float m;
    int board;
    int sensor;
    //    bool operator<(const nextBee& bee) const {
    ////        return bee.now < this->now || (bee.now == this->now && bee.m < this->m);
    //        for(int i = 0; i < 6; i ++){
    //                if(this->now[i] != bee.now[i] ){
    //                    return this->now[i] < bee.now[i];
    //                }
    //            }
    //            return this->m < bee.m  ;
    //    }

} ;

struct Compare{
    bool operator()(nextBee const& first, nextBee const& second)
    {
        for(int i = 0; i < 6; i ++){
            if(first.now[i] != second.now[i] ){
                return first.now[i] > second.now[i];
            }
        }
        return first.m > second.m  ;
    }
};


class BeeGeneration
{
public:
    BeeGeneration(int size);
    BeeGeneration(string _id, int size);
    BeeGeneration(string _id, int size, int time);
    ~BeeGeneration();
    float milli, m;

    string makeBee();
    void setSeed(unsigned int seed);
    void generateTime();
    void generateTime(int _time);
    void setActivity(int size);
    void update(float ms);
    vector<int> calculate(float ms);

    void generate();
    string generateUDP();
    string anotherActivity(string _udp, int _udpTime[], float _m);
    int findPair(int s);
    int btod(string b);
    void setID(string _id, int size);
    void setID(string _id, int size, int time);
    priority_queue<nextBee, vector<nextBee>, Compare> nextBees;
    void setDate(int year,int month, int date);
    int getNextTime(int);
    float getNextM();

    vector<int> nextUDP();
private:
    std::default_random_engine generator;
    vector<int> lambda;
    //int current;
    int n;
    double x;
    string id;
    int time[6];
    vector<int> next;




};

#endif // BEEGENERATION_H
