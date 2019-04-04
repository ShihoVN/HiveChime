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


//        dContainer.addData(d);


}

string DataDecoder:: activityDecoder(string _act){
        string act = _act;
        string delimiter = "B"; // set the delimeter






}

///**
// * @brief converts a decimal number to binary
// * @param hiveNum
// * @return bianry number
// */
//int DataDecoder:: decimalToBinary(int hiveNum){
//    int *binary = new int[32];
//    //an interger is only 32 bits long
//    //counter for binary array
//    int i =0;
//    while(hiveNum>0){
//        binary[i] = hiveNum%2;
//        hiveNum= hiveNum/2;
//        i++;
//    }
//    //must be added in the arry backwards though!!!!!
//}


int DataDecoder::decimalToBinary(int hiveNumber){

}
