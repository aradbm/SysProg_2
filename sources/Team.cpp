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
            members[size++] = new_char;
        else
            std::cout << "Team is already full. Cannot add more members." << std::endl;
    }

    // Character *Team::closestEnemy(Team *Other)
    // {
    //     // check closest charecter from other team and attack it with closest character
    //     for (size_t i = 0; i < MAX_SIZE; i++)
    //     {
    //         members[i]->isAlive();
    //     }
    // }
    void Team::attack(Team *other)
    {

        if (leader->isAlive())
        {
            std::cout << "Team " << leader->getName() << " attacks Team " << other->leader->getName() << std::endl;

            for (int i = 0; i < size; i++)
            {
                if (members[i]->isAlive() && other->size > 0)
                {
                    size_t k = 0;
                    for (size_t k = 0; k < other->size; k++)
                    {
                        if (other->members[k]->isAlive())
                            break;
                    }
                    Character *enemy = other->members[k];
                    // now attack or move to other[k] with this[i].
                    // if ninja than:
                    if (false)
                    {
                    }
                    else
                    {
                        // if cowboy than:
                        // members[i]->hit(20);
                        enemy->hit(20);
                        if (!enemy->isAlive())
                            std::cout << enemy->getName() << " from Team " << other->leader->getName() << " has been defeated." << std::endl;
                    }
                }
            }
        }
        else
            std::cout << "Team " << leader->getName() << " is defeated and cannot attack." << std::endl;
    }
    int Team::stillAlive()
    {
        int count = leader->isAlive() ? 1 : 0;
        for (int i = 0; i < size; i++)
        {
            if (members[i]->isAlive())
                count++;
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
    void SmartTeam::attack(Team *Other)
    {
    }
}