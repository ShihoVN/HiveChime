#include "datadecoder.h"

DataDecoder::DataDecoder()
{
    sa.sensors = 0;
    sa.sensorTime =0;
    sa.sensorBoard = 0;
    gateArr= new int[32]; //initalize gate ar
    boardArr = new int[10];
}

void DataDecoder::decode(string _hex){

    vector<string> fragments; //vector containing each segment
    stringstream ss(_hex); // Turn the string into a stream.
    string tok;

    while(getline(ss, tok, '-')) {
        fragments.push_back(tok);
        cout << "fragements_pushback  " <<tok << endl;
    }


    string hiveId = fragments.at(0);
    string date = dateDecoder(fragments.at(1));
    string time = timeDecoder(fragments.at(1));

    activityDecoder(fragments.at(2));

    cout << "sensor array" <<sensorArray.size() << endl;


    bool type = entry; //this isnt rigth


    Data d;
    d.hiveId = hiveId;
    d.date = date;
    d.time = time;
    d.gate = gateArr;
    d.board = boardArr;
    d.type = type;


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
    string tok2;
    int count = 0;
    string time;
    int t;
    vector <string> timeList;


    while(getline(ss, tok, 'T')) {
     //time = tok;
     getline(ss, tok, 'T');
     time = tok;

     cout << "THE TIMES "<< time << endl;

     //this doesnt work  i just need to get the miliseconds
    int pos = time.find('.');


    string sub = time.substr(pos+3);
     sub.erase(sub.begin());

    cout << "sub " <<sub << endl;
       int milisec = std::stoi(sub);


     //set sensor time to
     sa.sensorTime = milisec;
     cout << "sensor time " <<sa.sensorTime << endl;
    }


     cout << "time decoder " << tok << endl;
    return tok;

}

void DataDecoder:: activityDecoder(string _act){

        stringstream act(_act);
        string delimiter = "B"; // set the delimeter
        vector<int> boardNum;

        int boardIndex=0;

        //HELLO OKAY FOR SOME REASON THE FIRST INDEX OF THIS STRING
        //IS " " --- IM NOT SURE WHY-- BUT IF WE FIGURE OUT WHY
        //WE NEED TO CHANGE THE BOARD INDEX FROM 0 TO 1

        while(std::getline(act, delimiter, 'B'))
        {

           //seglist.push_back(delimiter); //LIA COMMENTED IT OUT

            int board = std::atoi(delimiter.c_str()); //convert the delimiter to an int

            //get rid of any 0s for complexity purpose
            if(board != 0){


               boardNum.push_back(boardIndex); //this vector stores which board showed activity-- not sure if we need to know
               //make struct sensors equal to this board

               sa.sensorBoard = boardIndex;

                cout << "board " << board << endl;
               decimalToBinary(board); //pass the board activity to binary decoder


               cout << "\n board Activity decimal "  << board<< endl;
               cout << "board Index "  << boardIndex<< endl;


            }

           boardIndex ++; //increase index for each loop
        }



}

void DataDecoder:: decimalToBinary2(int boardAct){
    //the higest gate we can have it 2^8
    //binary is read in backwards

    cout << "board act " << boardAct << endl;

    for(unsigned i = 32; i>0; i--){
        int temp = boardAct >> i; //bitwise operator
        cout << "this is temp" <<temp <<endl;
        //cout << "this is i " << i << endl;
        //cout << " LINE 155" << temp <<endl;
        //set struct sensor equal to i

        if(temp & 1) //and the bits with 1--to determine if they are one
        {
            cout << "this is i" <<i <<endl;

             cout << 1 <<endl;
            sa.sensors = i;
            compareSensors(sa);
             // sensorArray.push_back(sa); //add the struct to the vector of structs
            //cout <<"hellloo " << sa.sensors;

        }
//        else{
//            //cout << "0" << endl;
//            cout << 0 <<endl;
//            sa.sensors = i;
//            compareSensors(sa);
//           // sensorArray.push_back(sa); //add the struct to the vector of structs
//            //cout << sa.sensors;
//        }
    }


}

void DataDecoder:: compareSensors(sensorActivity thisSensor){
    for(unsigned i = 0; i<sensorArray.size(); i++){
        if(thisSensor.sensorTime - sensorArray.at(i).sensorTime < 500) //check if the sensor time < 500 ms
        {
            if(thisSensor.sensorBoard == sensorArray.at(i).sensorBoard) //check only sensors of the same board
            {
                //checks for sensors 8 & 1 and deletes sensor if its a match
                if(thisSensor.sensors == 8 || thisSensor.sensors ==1){
                    if(sensorArray.at(i).sensors ==1 || sensorArray.at(i).sensors ==8);
                        sensorArray.erase(sensorArray.begin() +(i)); //remove the struct in array
                        return;

                }
                //checks for sensors 2 & 7 and deletes sensor if its a match
                else if(thisSensor.sensors == 2 || thisSensor.sensors ==7){
                    if(sensorArray.at(i).sensors ==2 || sensorArray.at(i).sensors ==7);
                        sensorArray.erase(sensorArray.begin() +(i)); //remove the struct in array
                        return;

            }
                //checks for sensors 3 & 6 and deletes sensor if its a match
                else if(thisSensor.sensors == 3 || thisSensor.sensors ==6){
                    if(sensorArray.at(i).sensors ==6 || sensorArray.at(i).sensors ==3);
                        sensorArray.erase(sensorArray.begin() +(i)); //remove the struct in array
                        return;

                }
                //checks for sensors 4 & 5 and deletes sensor if its a match
                else if(thisSensor.sensors == 4 || thisSensor.sensors ==5){
                    if(sensorArray.at(i).sensors ==5 || sensorArray.at(i).sensors ==4);
                        sensorArray.erase(sensorArray.begin() +(i)); //remove the struct in array
                        return;

                }
                else{
                    sensorArray.push_back(thisSensor);
                }
            }

        }
        //if the time is more than 500 ms delete sensor .. bee turned back
        else{
                sensorArray.erase(sensorArray.begin() +i);
        }
        \

    }
}



void DataDecoder:: decimalToBinary(int boardAct){
    //the higest gate we can have it 2^8
    //binary is read in backwards
    int _boardAct = boardAct;
    int binary[32];
    unsigned count =0;
    while (_boardAct > 0){
           binary[count] = _boardAct %2;
           _boardAct = boardAct/2;

           count++;


        }

    for(int i = count-1; i >=0; i--){
        cout << binary[i];
       //   cout << "before if"<< endl;
         // cout << "count" <<count << endl;
          //cout << "i" <<i << endl;
        if(binary[i] == 1){
             cout << "helloo"<< endl;
            sa.sensors = i+1;

            cout << "DA SENSORS " <<sa.sensors;
        }
    }
}




