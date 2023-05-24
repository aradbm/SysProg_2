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
        void attack(Team *other)
        {
            if (other == nullptr)
                throw std::invalid_argument("Invalid enemy team");
            if (other->stillAlive() == 0)
                throw std::runtime_error("Attacking a dead team");
            if (leader == nullptr || !leader->isAlive())
            {
                leader = findEnemy(leader, members);
                if (leader == nullptr)
                    return;
            }

            if (other->stillAlive() > 0 && stillAlive() > 0)
            {
                Character *closestEnemy = nullptr;
                for (Character *character : members)
                {
                    if (character->isAlive())
                    {
                        closestEnemy = closestEnemy == nullptr ? findEnemy(leader, other->getMembers()) : closestEnemy;
                        if (Cowboy *cowboy = dynamic_cast<Cowboy *>(character))
                            cowboy->hasboolets() ? cowboy->shoot(closestEnemy) : cowboy->reload();
                        else if (Ninja *ninja = dynamic_cast<Ninja *>(character))
                            ninja->distance(closestEnemy) <= 1 ? ninja->slash(closestEnemy) : ninja->move(closestEnemy);
                    }
                    if (closestEnemy != nullptr && !closestEnemy->isAlive())
                    {
                        closestEnemy = findEnemy(leader, other->getMembers());
                        if (closestEnemy == nullptr)
                            return;
                    }
                }
            }
        }
        void print()
        {
            // just print by order of memebers
            std::cout << "Team Leader: " << leader->getName() << std::endl;
            std::cout << "Team Members: " << std::endl;
            for (vector<Character *>::size_type i = 0; i < members.size(); i++)
            {
                std::cout << members[i]->getName() << "," << members[i]->getLocation().getX() << "," << members[i]->getLocation().getY() << std::endl;
            }
        }
    };
};
