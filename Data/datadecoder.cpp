#include "datadecoder.h"

DataDecoder::DataDecoder()
{

}

void DataDecoder::decode(string _hex){

    vector<string> fragments; //vector containing each segment
    stringstream ss(_hex); // Turn the string into a stream.
    string tok;

    while(getline(ss, tok, '-')) {
        fragments.push_back(tok);
        //cout << tok << endl;
    }




    string hiveId = fragments.at(0);
    string date = dateDecoder(fragments.at(1));
    string time = timeDecoder(fragments.at(1));
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


string DataDecoder:: dateDecoder(string s){
    stringstream ss(s); // Turn the string into a stream.
    string tok;

    getline(ss, tok, 'T');
    tok.erase(tok.begin());

     cout << tok << endl;



    return tok;
}



string DataDecoder:: timeDecoder(string s){
    stringstream ss(s); // Turn the string into a stream.
    string tok;
    string time;

    while(getline(ss, tok, 'T')) {
     time = tok;
    }


     cout << tok << endl;
    return tok;

}

string DataDecoder:: activityDecoder(string _act){
    string act = _act;
    string delimiter = "B"; // set the delimeter






}

//**
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
