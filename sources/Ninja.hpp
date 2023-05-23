#pragma once

#include <string>
#include "Point.hpp"
#include "Character.hpp"

namespace ariel
{

    class Ninja : public Character
    {
    private:
        int speed;

    public:
        Ninja(string name, Point location, int speed, int hp) : Character(name, hp, location), speed(speed)
        {
        }
        void move(Character *other);
        void slash(Character *other);

        static const int on_hp = 150;
        static const int tn_hp = 120;
        static const int yn_hp = 100;
        static const int on_speed = 8;
        static const int tn_speed = 12;
        static const int yn_speed = 14;
    };
};