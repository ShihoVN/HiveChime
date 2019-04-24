#include "bees.h"
#include <iostream>
#include <ctime>
using namespace std;

/**
 * Default constructor
 * Sets rows & columns to 20
 * */
Bees::Bees(){
    numberOfBees = NUM_BEES;
    num_rows = 23;
    num_cols = 120;
    gate.insert(gate.end(),pair<int,int>(7,25));
    gate.insert(gate.end(),pair<int,int>(18,45));
    gate.insert(gate.end(),pair<int,int>(15,50));
    gate.insert(gate.end(),pair<int,int>(11,60));
    gate.insert(gate.end(),pair<int,int>(9,80));
    gate.insert(gate.end(),pair<int,int>(13,98));
    num_cols = 84;
    init_game();
}

/**
 * Over-ride constructor
 * Sets the variable for rows and colums to the input the user passed in
 * */
Bees::Bees(int row, int col,std::vector<pair<int,int>> _gate){
    numberOfBees = NUM_BEES;
    num_rows = row;
    num_cols = col;
    gate=_gate;
    init_game();
}

/**
 * Destructor
 * */
Bees::~Bees(){
}


/**
 * Initalizes the game
 * */
void Bees::init_game(){
    score = 0;//Set score to 0
    reset_gameboard(); //Draws the gameboard
    for (int i=0;i<numberOfBees;i++) {
        bee.push_back(add_random('b',4));//Fills the vecBeetor with random Bee
    }
}

/**
 * Updates the current gamebaord (resets gamebaord then resets all positons on board)
 * */
void Bees::update(){
    reset_gameboard();
    for (int i = 0; i < numberOfBees; i++) { //Sets the Bee
        board[ bee.at(i).row][ bee.at(i).col] = 'b';
    }
    for (int i = 0; i < gate.size(); i++) { //Sets the Bee
        board[ gate.at(i).first][ gate.at(i).second] = '0';
    }
}

/**
 *Steps through the game once
 * @Param direction: Given direction to move a player
 * */
void Bees::step(){
    move_bees(); //Move bees
    update(); //Updates gamebaord
    check_bees();
}

void Bees::add_bee(int gate,bool enter){
    if(enter){
        add_random('b',gate);
    }
    else {
        add_thing('b',gate);
    }
}


/**
 * Moves the bees towards the player
 * Checks to see if a Bee rows or cols is greater than or less than the Bee
 * Some flaws
 * */
void Bees::move_bees(){
    for (int i=0; i < bee.size();i++){
        //if(bee.at(i).gate.first !=  bee.at(i).row && bee.at(i).gate.second != this-> bee.at(i).col){
        if(bee.at(i).row != (num_rows - 1)){
            if (bee.at(i).gate.first >  bee.at(i).row){
                bee.at(i).row =  this-> bee.at(i).row + 1;
            } else if (bee.at(i).gate.first < this-> bee.at(i).row){
                this-> bee.at(i).row =  this-> bee.at(i).row - 1;
            }
        }
        if(bee.at(i).col != (num_cols - 1)){
            if (bee.at(i).gate.second > this-> bee.at(i).col){
                this-> bee.at(i).col = this-> bee.at(i).col + 1;
            } else if (bee.at(i).gate.second < this-> bee.at(i).col){
                this-> bee.at(i).col = this-> bee.at(i).col - 1;
            }
        }
    }
}

/**
 * Checks to see if a bee has entered a hive through a gate.
 * */
void Bees::check_bees(){ //Should this be a bool
    //for = myvector.begin() ; it != myvector.end(); ++it)
    for (int i = 0; i <  bee.size(); i++) { //Checks to see if a bees hit a will
        if (bee.at(i).row ==  bee.at(i).gate.first &&  bee.at(i).col ==  bee.at(i).gate.second){
            remove_thing(bee.at(i).row, bee.at(i).col); //Removes the char from the baord
            bee.erase(bee.begin()+i); //Erases bees in bees vector based on index
            numberOfBees=numberOfBees-1;
            score = score+1;
            //return true;
        }
    }
}


/**
 * Getter method for returning number of Bee
 * */
int Bees::getNumberOfBees(){
    return numberOfBees;
}

/**
 * Gets the current score of the player
 * */
int Bees::get_score(){
    return score;
}
