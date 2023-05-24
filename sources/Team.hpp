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
    protected:
        Character *leader;
        vector<Character *> members;
        int size;

    public:
        // getters, setters, c'tors, d'tors
        Team(Character *leader);
        ~Team();
        int getSize() { return size; }
        Character *getLeader() { return leader; }
        vector<Character *> &getMembers() { return members; }

    public:
        // methods
        int stillAlive();
        void add(Character *new_char);
        void virtual attack(Team *other);
        void virtual print();
        void leaderDead();
        Character *closestEnemy(Team *Other);
        Character *findEnemy(Character *leader, std::vector<Character *> &members);
    };

    class SmartTeam : public Team
    {
    public:
        SmartTeam(Character *leader) : Team(leader) {}
        void attack(Team *Other);
        void print();
    };
};
