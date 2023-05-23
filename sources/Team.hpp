#pragma once

#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include <vector>
const static int MAX_SIZE = 10;

namespace ariel
{
    class Team
    {
    private:
        Character *leader;
        vector<Character *> members;
        int size;

    public:
        Team(Character *leader);
        virtual ~Team();
        void add(Character *new_char);
        void virtual attack(Team *other);
        Character *closestEnemy(Team *Other);
        int stillAlive();
        void virtual print();
        void leaderDead();
    };

    class SmartTeam : public Team
    {
    public:
        SmartTeam(Character *leader) : Team(leader) {}
        void attack(Team *Other);
    };
};
