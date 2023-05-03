#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
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
        string getName();
        Point getLocation();

    public:
        Character(string name, int health, Point location);
        string print();
        bool virtual isAlive();
        double virtual distance(Character &other);
        void virtual hit(Character &other);
    };
};

#endif