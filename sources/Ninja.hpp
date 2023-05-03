#pragma once

#include <iostream>
#include <string>
#include <math.h>
#include "Point.hpp"
#include "Character.hpp"

namespace ariel
{

    class Ninja : public Character
    {
    private:
        int speed;

    public:
        Ninja(string name, Point location, int speed, int hp) : Character(name, hp, location), speed(speed) {}
        void move(Character *other);
        void slash(Character *other);

        static const int on_hp = 150;
        static const int tn_hp = 120;
        static const int yn_hp = 100;
        static const int on_speed = 10;
        static const int tn_speed = 12;
        static const int yn_speed = 15;
    };

    class OldNinja : public Ninja
    {
    public:
        OldNinja(string name, Point location) : Ninja(name, location, on_speed, on_hp) {}
    };

    class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(string name, Point location) : Ninja(name, location, tn_speed, tn_hp) {}
    };

    class YoungNinja : public Ninja
    {
    public:
        YoungNinja(string name, Point location) : Ninja(name, location, yn_speed, yn_hp) {}
    };

};