#pragma once

#include "Point.hpp"
#include "Team.hpp"
#include "Character.hpp"

namespace ariel
{
    class Team2 : public Team
    {
    public:
        Team2(Character *leader) : Team(leader) {}
        void add(Character *new_char)
        {
            if (new_char->getInGame())
                throw std::runtime_error("Character is already in a team");
            if (size >= MAX_SIZE)
                throw std::runtime_error("Team is full");
            members.push_back(new_char);
            new_char->setInGame(true);
            size++;
        }
    };
};
