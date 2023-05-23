#include "Team.hpp"
#include <stdexcept>
#include <limits>
#include <iostream>
#include <algorithm>
namespace ariel
{
    Team::Team(Character *leader) : leader(leader)
    {
        if (leader->getInGame())
        {
            throw std::runtime_error("Character is already in a team");
        }

        members.push_back(leader);
        leader->setInGame(true);
        size = 1;
    }

    Team::~Team()
    {
        members.clear();
    }
    void Team::add(Character *new_char)
    {
        if (new_char->getInGame())
        {
            throw std::runtime_error("Character is already in a team");
            return;
        }

        if (size >= MAX_SIZE)
        {
            throw std::runtime_error("Team is full");
            return;
        }

        members.push_back(new_char);
        new_char->setInGame(true);
        size++;
    }
    void Team::leaderDead()
    {
        // change to closest alive member
        for (vector<Character *>::size_type i = 0; i < members.size(); i++)
        {
            if (members[i]->isAlive())
            {
                leader = members[i];
                return;
            }
        }
    }

    void Team::attack(Team *other)
    {
        if (other == nullptr)
        {
            throw std::invalid_argument("Team is null");
        }
        if (this == other)
        {
            throw std::invalid_argument("Team is attacking itself");
        }
        if (other->stillAlive() == 0)
        {
            throw std::runtime_error("Team is dead");
        }

        if (leader->isAlive() && other->leader->isAlive())
        {
            for (Character *attacker : members)
            {
                if (!attacker->isAlive())
                {
                    continue; // Skip dead attackers
                }

                Character *closestEnemy = nullptr;
                double minDistance = std::numeric_limits<double>::max();

                for (Character *enemy : other->members)
                {
                    if (!enemy->isAlive())
                    {
                        continue; // Skip dead enemies
                    }

                    double distance = attacker->distance(enemy);
                    if (distance < minDistance)
                    {
                        minDistance = distance;
                        closestEnemy = enemy;
                    }
                }

                if (closestEnemy != nullptr)
                {
                    Cowboy *cowboy = dynamic_cast<Cowboy *>(attacker);
                    if (cowboy != nullptr)
                    {
                        cowboy->shoot(closestEnemy);
                    }
                    else
                    {
                        Ninja *ninja = dynamic_cast<Ninja *>(attacker);
                        if (ninja != nullptr)
                        {
                            if (minDistance <= 1.0)
                            {
                                ninja->slash(closestEnemy);
                            }
                            else
                            {
                                ninja->move(closestEnemy);
                            }
                        }
                    }

                    if (!closestEnemy->isAlive())
                    {
                        if (closestEnemy == other->leader)
                        {
                            other->leaderDead();
                        }
                        // Remove dead enemy from other team
                        for (auto it = other->members.begin(); it != other->members.end(); ++it)
                        {
                            if (!(*it)->isAlive())
                            {
                                other->members.erase(it);
                                break;
                            }
                        }
                        other->size--;
                    }
                }
            }
            other->members.erase(std::remove_if(other->members.begin(), other->members.end(),
                                                [](Character *character)
                                                { return !character->isAlive(); }),
                                 other->members.end());
            other->size = other->members.size();
        }
        else
        {
        }
    }

    int Team::stillAlive()
    {
        int count = 0;
        for (vector<Character *>::size_type i = 0; i < members.size(); i++)
        {
            if (members[i]->isAlive())
            {
                count++;
            }
        }
        return count;
    }

    void Team::print()
    {
        std::cout << "Team Leader: " << leader->getName() << std::endl;
        std::cout << "Team Members: " << std::endl;
        for (vector<Character *>::size_type i = 0; i < members.size(); i++)
        {
            std::cout << members[i]->getName() << "," << members[i]->getLocation().getX() << "," << members[i]->getLocation().getY() << std::endl;
        }
    }
}
