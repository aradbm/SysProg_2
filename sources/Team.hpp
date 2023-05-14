#pragma once

#include "Character.hpp"
#include "Point.hpp"

namespace ariel
{
    class Team
    {
        Character *leader;
        Character *members[10];
        int size;

    private:
    public:
        Team(Character *leader);
        virtual ~Team();
        void add(Character *new_char);
        void attack(Team *other);
        int stillAlive();
        void print();
    };

    class SmartTeam : public Team
    {
    public:
        void virtual print();
    };
};
