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



using namespace std;


class BeeGeneration
{
public:
    BeeGeneration(string filename);
    BeeGeneration(string id, string filename);
    ~BeeGeneration();

    string makeBee();
    void generateTime();
    void setID(string id);
    void setID(string id, string filename);
private:
    std::default_random_engine generator;
    vector<int> lambda;
    int current;
    int n;
    string id;
    long milli;
    int time[6];
    void add(long ms);


};

#endif // BEEGENERATION_H
