#pragma once

#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character
    {
    private:
        int bullets;

    public:
        static const int cb_hp = 110;
        Cowboy(string name, Point location) : Character(name, cb_hp, location), bullets(6) {}
        void shoot(Character *other);
        bool hasboolets();
        void reload();
    };
};
