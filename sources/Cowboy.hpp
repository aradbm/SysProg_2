#pragma once

#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character
    {
    private:
        int bullets;

    public:
        Cowboy(string name, Point location) : Character(name, 110, location), bullets(6) {}
        void print();
        void hit(Character &other);
        bool isAlive();
        double distance(Character &other);

        void shoot(Character &other);
        bool hasBullets();
        void reload();
    };
};
