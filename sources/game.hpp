#ifndef GAME_H
#define GAME_H

#include "player.hpp"

namespace ariel
{
    class Game
    {
        Player p1;
        Player p2;

    public:
        Game(Player player1, Player player2);
        ~Game();
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
    };
};

#endif