#include "Team.hpp"

namespace ariel
{
    Team::Team(Character *leader) : leader(leader), size(0)
    {
        for (int i = 0; i < 10; i++)
        {
            members[i] = nullptr;
        }
    }

    Team::~Team()
    {
        for (int i = 0; i < size; i++)
        {
            delete members[i];
        }
        delete leader;
    }

    void Team::add(Character *new_char)
    {
        if (size < 10)
        {
            for (int i = 0; i < size; i++)
            {
                if (members[i] == new_char)
                {
                    std::cout << "Character is already in the team. Cannot add duplicates." << std::endl;
                    return;
                }
            }
            members[size++] = new_char;
        }
        else
        {
            throw std::runtime_error("Team is full. Cannot add more characters.");
        }
    }
    void Team::attack(Team *other)
    {
        if (leader->isAlive() && other->leader->isAlive())
        {
            std::cout << "Team " << leader->getName() << " attacks Team " << other->leader->getName() << std::endl;

            for (int i = 0; i < size; i++)
            {
                if (members[i]->isAlive() && other->size > 0)
                {
                    Character *enemy = nullptr;
                    for (int k = 0; k < other->size; k++)
                    {
                        if (other->members[k]->isAlive())
                        {
                            enemy = other->members[k];
                            break;
                        }
                    }
                    // Check the type of character and call the appropriate attack function.
                    Cowboy *cowboy = dynamic_cast<Cowboy *>(members[i]);
                    if (cowboy)
                    {
                        cowboy->shoot(enemy);
                    }
                    else
                    {
                        // It's some type of Ninja.
                        Ninja *ninja = dynamic_cast<Ninja *>(members[i]);
                        if (ninja)
                        {
                            ninja->slash(enemy);
                        }
                    }
                    if (enemy && !enemy->isAlive())
                    {
                        std::cout << enemy->getName() << " from Team " << other->leader->getName() << " has been defeated." << std::endl;
                    }
                }
            }
        }
        else
        {
            std::cout << "Team " << leader->getName() << " is defeated and cannot attack." << std::endl;
        }
    }

    int Team::stillAlive()
    {
        int count = leader->isAlive() ? 1 : 0;
        for (int i = 0; i < size; i++)
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
        for (int i = 0; i < size; i++)
        {
            std::cout << members[i]->getName() << std::endl;
        }
    }
}
