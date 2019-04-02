#include "beegeneration.h"


BeeGeneration::BeeGeneration(string filename)
{
    ifstream myfile(filename);

    int line;
    if(myfile.is_open()){
        while(!myfile.eof()){
            myfile >> line;
            lambda.push_back(line);
        }
    }
    else{
        cerr << "error" << endl;
    }
    myfile.close();
    generateTime();
}

BeeGeneration::BeeGeneration(string filename, string iD1){
    ifstream myfile(filename);

    int line;
    if(myfile.is_open()){
        while(!myfile.eof()){
            myfile >> line;
            lambda.push_back(line);
        }
    }
    else{
        cerr << "error" << endl;
    }
    myfile.close();

    id = iD1;
    generateTime();
}

void BeeGeneration::setID(string iD1){
    id = iD1;
    return;
}

BeeGeneration::~BeeGeneration()
{

}

string BeeGeneration::makeBee()
{
    date = year/month/day;



    //make sure incrememnt time
    //milli+=


}

void BeeGeneration::generateTime(){
    year = rand() % 100;
    year += 2000;
    month = rand() % 12 + 1;
    day = rand() % 30 + 1;






    //set a time;
}
