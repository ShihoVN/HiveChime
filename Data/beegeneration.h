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



using namespace std::chrono;
using namespace std;


class BeeGeneration
{
public:
    BeeGeneration(string filename);
    BeeGeneration(string filename, string id);
    ~BeeGeneration();

    string makeBee();
    void generateTime();
    void setID(string id);
private:
    vector<int> lambda;
    string id;
    string year, month, day;
    auto date;
    string hour, min, sec, milli;

};

#endif // BEEGENERATION_H
