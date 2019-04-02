#include "datadecoder.h"

DataDecoder::DataDecoder()
{

}

void DataDecoder::decode(string _hex){
    hex = _hex;
    string hiveId = "bbdsd";
    string date =  "09099";
    string time = "0897";
    int  gate =  7;
    bool type = true;


    Data d;
        d.hiveId = hiveId;
        d.date = date;
        d.time = time;
        d.gate = gate;
        d.type = type;


        dContainer.addData(d);


}
