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
        // cowboys first than ninjas
        if (new_char->getInGame())
            throw std::runtime_error("Character is already in a team");

        if (size >= MAX_SIZE)
            throw std::runtime_error("Team is full");

        members.push_back(new_char);
        new_char->setInGame(true);
        size++;
    }

    Character *Team::findEnemy(Character *leader, std::vector<Character *> &members)
    {
        double minDistance = std::numeric_limits<double>::max();
        Character *closestCharacter = nullptr;
        for (Character *character : members)
        {
            if (character->isAlive())
            {
                double distance = leader->distance(character);
                if (distance < minDistance)
                {
                    minDistance = distance;
                    closestCharacter = character;
                }
            }
        }
        return closestCharacter;
    }

    void Team::attack(Team *other)
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
                    closestEnemy = closestEnemy == nullptr ? findEnemy(leader, other->members) : closestEnemy;
                    if (Cowboy *cowboy = dynamic_cast<Cowboy *>(character))
                        cowboy->hasboolets() ? cowboy->shoot(closestEnemy) : cowboy->reload();
                    else if (Ninja *ninja = dynamic_cast<Ninja *>(character))
                        ninja->distance(closestEnemy) <= 1 ? ninja->slash(closestEnemy) : ninja->move(closestEnemy);
                }
                if (closestEnemy != nullptr && !closestEnemy->isAlive())
                {
                    closestEnemy = findEnemy(leader, other->members);
                    if (closestEnemy == nullptr)
                        return;
                }
            }
        }
    }

    int Team::stillAlive()
    {
        int count = 0;
        for (vector<Character *>::size_type i = 0; i < members.size(); i++)
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
        for (vector<Character *>::size_type i = 0; i < members.size(); i++)
        {
            std::cout << members[i]->getName() << "," << members[i]->getLocation().getX() << "," << members[i]->getLocation().getY() << std::endl;
        }
    }
}
