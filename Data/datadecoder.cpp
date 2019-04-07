#include "datadecoder.h"

DataDecoder::DataDecoder()
{
    sa.sensors = 0;
    sa.sensorTime =0;
    sa.sensorBoard = 0;
    _type = NULL;
    miliseconds = 0;
}

void DataDecoder::decode(string _hex){

    vector<string> fragments; //vector containing each segment
    stringstream ss(_hex); // Turn the string into a stream.
    string tok;

    while(getline(ss, tok, '-')) {
        fragments.push_back(tok);
        cout << "fragements_pushback  " <<tok << endl;
    }

    string _hiveId = fragments.at(0);
    string _date = dateDecoder(fragments.at(1));
    string _time = timeDecoder(fragments.at(1));

    activityDecoder(fragments.at(2));



    Data d;
    d.hiveId = _hiveId;
    d.date = _date;
    d.time = _time;
    d.gate = gateArr;
    d.board = boardArr;
    d.type = _type;

    cout << "sensor array" <<sensorArray.size() << endl;
    //        dContainer.addData(d);


}


string DataDecoder:: dateDecoder(string s){
    stringstream ss(s); // Turn the string into a stream.
    string tok;

    getline(ss, tok, 'T'); //gets line up to character T
    tok.erase(tok.begin());  //erases D in the begining of string

    cout << "date decoder  " << tok << endl;

    return tok;
}



string DataDecoder:: timeDecoder(string s){
    stringstream ss(s); // Turn the string into a stream.
    string tok;
    string time;
    string sub;
    vector <string> timeList;
    unsigned int pos;
    int sec_mili;

    while(getline(ss, tok, 'T')) {
        if(tok.at(0)!='D'){
            time = tok;
            cout << "sensor time " <<time << endl;
        }
    }

    pos = time.find_last_of('.');
    sub = time.substr(pos);
    sub.erase(sub.begin());
    cout << "sub " << sub<< endl;
    sec_mili = std::stoi(sub);

    //set sensor time
    //sa.sensorTime[0] = hour;
    //sa.sensorTime[1] = min;
    sa.sensorTime = sec_mili;

    cout << "sensor time " <<sa.sensorTime << endl;
    return time;

}


void DataDecoder:: activityDecoder(string _act){
    cout << "HEREE" << endl;
    stringstream act(_act);
    string delimiter; // set the delimeter
    vector<int> boardNum;
    int board;
    int boardIndex=0;

    //HELLO OKAY FOR SOME REASON THE FIRST INDEX OF THIS STRING
    //IS " " --- IM NOT SURE WHY--- BUT IF WE FIGURE OUT WHY
    //WE NEED TO CHANGE THE BOARD INDEX FROM 0 TO 1

    while(std::getline(act, delimiter, 'B'))
    {

        //seglist.push_back(delimiter); //LIA COMMENTED IT OUT

        board = std::atoi(delimiter.c_str()); //convert the delimiter to an int

        //get rid of any 0s for complexity purpose
        if(board != 0){


            boardNum.push_back(boardIndex); //this vector stores which board showed activity-- not sure if we need to know
            //make struct sensors equal to this board
            sa.sensorBoard = boardIndex;

            cout << "board " << board << endl;
            decimalToBinary(board); //pass the board activity to binary decoder


            cout << "board Activity decimal "  << board<< endl;
            cout << "board Index "  << boardIndex<< "\n"<< endl;


        }

        boardIndex ++; //increase index for each loop
    }



}

void DataDecoder:: compareSensors(sensorActivity thisSensor){

    //if the array is empty just add sensor
    if(sensorArray.size() ==0){
        sensorArray.push_back(thisSensor);
        cout << "sensor " << thisSensor.sensors<< " added " << endl;

        return;
    }

    //run through array
    for(unsigned i = 0; i<sensorArray.size(); i++){

        //remove all sensors that were > than 500s ago
        if(thisSensor.sensorTime - sensorArray.at(i).sensorTime > 500)
        {
            sensorArray.erase(sensorArray.begin() +(i));
        }

        if(thisSensor.sensorBoard == sensorArray.at(i).sensorBoard) //check only sensors of the same board
        {
            if(sensorArray.at(i).sensors == getPair(thisSensor.sensors)){
                //send info into data base
                if(getPair(thisSensor.sensors) >=4){
                    _type = 1;  //bee entered the hive
                }
                else if(getPair(thisSensor.sensors) <=8){
                    _type = 0; // bee left the hive
                }
                cout << "removed " << sensorArray.at(i).sensors << endl;
                sensorArray.erase(sensorArray.begin() +(i)); //remove the struct in array
                return;
            }

        }

    }

    //if the sensor does not have a pair then add it to the array
    sensorArray.push_back(thisSensor);
    cout << "sensor " << thisSensor.sensors<< " added " << endl;

}



void DataDecoder:: decimalToBinary(int boardAct){
    int _boardAct = boardAct;
    int binary[32];
    unsigned count =0;

    //convert to binary
    while (_boardAct > 0){
        binary[count] = _boardAct %2;
        _boardAct = _boardAct/2;
        count++;
    }
    //binary is read in backwards
    for(int i = count-1; i >=0; i--){
        if(binary[i] == 1){
            sa.sensors = i+1; //set the sensor to the index == 1
            compareSensors(sa);
        }
    }
}

int DataDecoder::getPair(int sensorNum){
    switch(sensorNum){
    case 1 : return 8;
    case 2 : return 7;
    case 3 : return 6;
    case 4 : return 5;
    case 5 : return 4;
    case 6 : return 3;
    case 7 : return 2;
    case 8 : return 1;

    default: return 0;


    }
}






