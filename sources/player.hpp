#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;
namespace ariel
{
    class Player
    {
        string name;

    public:
        Player();
        ~Player();
        Player(string name);
        int stacksize();
        int cardesTaken();
    };
};
#endif