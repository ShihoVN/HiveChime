#ifndef ENGINE_H
#define ENGINE_H

#include <array>
#include <iostream>
#include <ctime> // For Robot
#include <sstream>
#include <string>
#include <stdlib.h>

using namespace std;

struct Bee
{
    int col;
    int row;
    bool enter_exit;
    pair<int,int> gate;
};

class engine
{
public:
    engine();
    engine(int r, int c);
    engine(int r, int c, int x, int y);
    ~engine();

    char** getBoard();


    char getBrdSpc(int x, int y);


    bool nullPtrCheck();

    void printBoard();

    //---Engines like his//
    void reset_gameboard();
    Bee add_thing(char item, int row, int col,bool enter_exit, pair<int,int> gate);
    Bee add_random(char item);
    void remove_thing(int row, int col);
    char get_thing(int row, int col);
    int get_num_rows();
    int get_num_cols();

private:

protected:
    char **board;  //creates gameboard array
    int num_rows;
    int num_cols;
    char plr;

};

#endif // ENGINE_H
