#ifndef ROBOTS_H
#define ROBOTS_H
#define NUM_BEES 20

#include <iostream>
#include <vector>
#include "engine.h"



using namespace std;

class Bees : public engine
{
public:
    Bees();
    ~Bees();
    Bees(Bees &obj);
    Bees(int row, int col,std::vector<pair<int,int>> _gate);

    void init_game();
    void update();
    void step();
    void add_bee(int gate,bool enter);
    void move_bees();
    void check_bees();
    void bees_leaving();
    void create_bee_vectors();

    int get_score();

    int getNumberOfBees();

private:

    std::vector<Bee> bee;
    std::vector<Bee> beeLeaving;
    int score;
    int numberOfBees;

};

#endif // ROBOTS_H
