#ifndef DATADECODER_H
#define DATADECODER_H
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
<<<<<<< HEAD

=======
>>>>>>> 420866f54cad501e228606778a8b15224cdf62ee
#include <datacontainer.h>


using namespace std;


class DataDecoder
{
public:
    DataDecoder();
    void decode(string hex);//decodes the string
    string getDecoded();
    string timeDecoder(string s);//take the time info from
    string dateDecoder(string s);
    string activityDecoder(string act);
    int decimalToBinary(int hiveNumber);



private:
    string hex;//The string before it is decompiled
    DataContainer dContainer;
    vector <string> hexArr; //array of data string entries
    vector <string> activityMessage;

};

#endif // DATADECODER_H
