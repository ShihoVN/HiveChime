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
    string tok2[3];
    int count = 0;
    string time;


    while(getline(ss, tok, 'T')) {
     time = tok;
}
     //this doesnt work  i just need to get the miliseconds
     for(char m : tok){
         if(m=='.')
             count++;
         else
             tok2[count]=tok2[count]+m;
     }
     sa.sensorTime = atoi(tok2[count].c_str());
      cout << "time at 2 "<< sa.sensorTime << endl;
     //set sensor time to

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

               decimalToBinary(board); //pass the board activity to binary decoder


               cout << "\n board Activity hex "  << board<< endl;
               cout << "board Index "  << boardIndex<< endl;


            }

           boardIndex ++; //increase index for each loop
        }



}

void DataDecoder:: decimalToBinary(int boardAct){
    //the higest gate we can have it 2^8
    //binary is read in backwards
    for(int i = 31; i>=0; i--){
        int temp = boardAct >>i; //bitwise operator
        //set struct sensor equal to i

        if(temp & 1) //and the bits with 1--to determine if they are one
        {
            sa.sensors = i;
            sensorArray.push_back(sa);  //add the struct to the vector of structs
            cout << sa.sensors;

        }
        else{
            sa.sensors = i;
            sensorArray.push_back(sa); //add the struct to the vector of structs
            cout << sa.sensors;
        }
    }


}



