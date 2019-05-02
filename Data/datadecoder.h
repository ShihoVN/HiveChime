#ifndef DATADECODER_H
#define DATADECODER_H
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "datacontainer.h"


using namespace std;

struct sensorActivity {
    int sensorTime;
    int sensorBoard;
    int sensors;
};

class DataDecoder
{
public:
    DataDecoder( DataContainer *container);
    void decode(string hex);//decodes the string
    string getDecoded();
    string timeDecoder(string s);//take the time info from
    string dateDecoder(string s);
    void activityDecoder(string act);
    void decimalToBinary(int hiveNumber);
     void decimalToBinary2(int hiveNumber);
    void compareSensors(sensorActivity sen);
    void livestream(sensorActivity thisSensor);
    int getPair(int sensorNum);
    bool sendExitAlert();
    bool sendEntryAlert();



private:
    string hex;//The string before it is decompiled
    DataContainer *dContainer;
    vector <string> hexArr; //array of data string entries
    int _gate;
    int _board;
    //vector <int> binaryMessage;
    int miliseconds;
    sensorActivity sa;
    vector <sensorActivity> sensorArray;
    bool _type;
    Data *d;
    int exitData;
    int entryData;
    int mean;



};

#endif // DATADECODER_H
