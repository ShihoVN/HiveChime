#include <iostream>
#include <string>
#include "datadecoder.h"
#include "datacontainer.h"
#include "datagenerator.h"

using namespace std;

int main()
{
    DataDecoder d;
    d.decode("HC0002-D18.12.19T13.43.16000-B0B1B16B0B0B0B0B0B0B0");
    d.decode("HC0002-D99.4.1T13.43.16400-B0B0B160B0B0B0B0B0B0B0");
    d.decode("HC0002-D99.4.1T13.43.16400-B0B0B5B0B0B0B0B0B0B0");





    return 0;
}
