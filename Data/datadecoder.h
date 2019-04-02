#ifndef DATADECODER_H
#define DATADECODER_H
#include <string>
#include <datacontainer.h>


using namespace std;


class DataDecoder
{
public:
    DataDecoder();
    void decode(string hex);//decodes the string
    string getDecoded();
    DataContainer d;


private:
    string hex;//The string before it is decompiled
};

#endif // DATADECODER_H
