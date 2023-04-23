// make mydemo && ./mydemo
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

using namespace std;
using namespace ariel;

int main()
{
     // Create two players with their names
     Player p1("Alice");
     Player p2("Bob");
     Game game(p1, p2);

     while (p1.stacksize() != 0 && p2.stacksize() != 0) // Loop until the game is over
     {
          game.playTurn();
          game.printLastTurn(); // print the last turn stats
     }
     game.printStats();

     cout << endl
          << "Game Over" << endl
          << endl
          << endl;

     cout << endl
          << "Game 1";
     Player p3("Alice");
     Player p4("Bob");
     Game game1(p3, p4);
     game1.playAll(); // playes the game untill the end
     game1.printStats();
     game1.printWiner();

     cout << endl
          << "Game 2";
     Player p5("Alice");
     Player p6("Bob");
     Game game2(p5, p6);
     game2.playAll(); // playes the game untill the end
     game2.printStats();
     game2.printWiner();

     cout << endl
          << "Game 3";
     Player p7("Alice");
     Player p8("Bob");
     Game game3(p7, p8);
     game3.playAll(); // playes the game untill the end
     game3.printStats();
     game3.printWiner();
}
