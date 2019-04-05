#ifndef DATADECODER_H
#define DATADECODER_H
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <datacontainer.h>


using namespace std;


class DataDecoder
{
public:
    DataDecoder();
    void decode(string hex);//decodes the string
    string getDecoded();
    string timeDecoder(string time);
    string activityDecoder(string act);
    int decimalToBinary(int hiveNumber);



private:
    string hex;//The string before it is decompiled
    DataContainer dContainer;
    vector <string> hexArr; //array of data string entries
    vector <string> activityMessage;

};

#endif // DATADECODER_H
