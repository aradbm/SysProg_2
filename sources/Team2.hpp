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
        void virtual print()
        {
            std::cout << "Team2" << std::endl;
        }
    };
};
