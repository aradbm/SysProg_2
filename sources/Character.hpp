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

    public:
        string getName() const { return name; }
        Point getLocation() const { return location; }

    public:
        Character(string name, int health, const Point &location);
        string print();
        bool virtual isAlive();
        double distance(Character *other);
        void hit(double value);
    };
};

#endif