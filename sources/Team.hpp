#pragma once

#include "Team2.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"
// #include "OldNinja.hpp"
#include "Ninja.hpp"
// #include "TrainedNinja.hpp"
// #include "YoungNinja.hpp"
#include "Point.hpp"

namespace ariel
{
    class Team
    {
        Character &leader;
        Character *members[10];
        int size;

    private:
    public:
        Team(Character &leader);
        ~Team();
        void add(Character &new_char);
        void attack(Team other);
        int stillAlive();
        void virtual print();
    };
};
