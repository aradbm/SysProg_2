#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <math.h>
#include "Point.hpp"
using namespace std;

namespace ariel
{
    class Character
    {
    private:
        string name;
        int health;
        Point location;
        bool inGame;

    public:
        string getName() const { return name; }
        Point getLocation() const { return location; }
        void setLocation(Point location) { this->location = location; }
        int getHealth() const { return health; }
        bool getInGame() const { return inGame; }
        void setInGame(bool inGame) { this->inGame = inGame; }

    public:
        Character(string name, int health, const Point &location);
        string print();
        bool virtual isAlive();
        double distance(Character *other);
        void hit(double value);
    };
};

#endif