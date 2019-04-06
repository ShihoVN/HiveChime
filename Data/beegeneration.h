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



using namespace std;

struct nextBee{
    int now[6];
    long m;
    int board;
    int sensor;
    bool operator<(const nextBee& bee) const {
        return bee.now < this->now || (bee.now == this->now && bee.m < this->m);
    }
} ;


class BeeGeneration
{
public:
    BeeGeneration(int size);
    BeeGeneration(string _id, int size);
    BeeGeneration(string _id, int size, int time);
    ~BeeGeneration();

    string makeBee();

    void setID(string _id, int size);
    void setID(string _id, int size, int time);
private:
    void generateTime();
    void generateTime(int _time);
    void setActivity(int size);
    int compare();
    int* calculate(long ms);
    string generate();
    string pairGenerate();
    string overGenerate( string udp);
    int findPair(int s);


    std::default_random_engine generator;
    vector<int> lambda;
    int current;
    int n, x;
    string id;
    long milli, m;
    int time[6];
    priority_queue<nextBee> nextBees;

};

#endif // BEEGENERATION_H
