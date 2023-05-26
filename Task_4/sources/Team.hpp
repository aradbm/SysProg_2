#pragma once

#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include <vector>
#include <stdexcept>
#include <limits>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

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
        Character virtual *findEnemy(Character *leader, std::vector<Character *> &members);
    };

    class SmartTeam : public Team
    {
    public:
        SmartTeam(Character *leader) : Team(leader) {}
        Character *findEnemy(Character *leader, std::vector<Character *> &members)
        {
            double maxDistance = 10.0;
            double minHealth = 20.0;
            double minDistance = std::numeric_limits<double>::max();
            Character *closestCharacter = nullptr;
            Character *weakestCharacter = nullptr;

            for (Character *character : members)
            {
                if (character->isAlive())
                {
                    double distance = leader->distance(character);
                    double health = character->getHealth();
                    if (distance < minDistance)
                    {
                        minDistance = distance;
                        closestCharacter = character;
                    }
                    if (distance <= maxDistance && health < minHealth)
                    {
                        minHealth = health;
                        weakestCharacter = character;
                    }
                }
            }
            if (weakestCharacter != nullptr)
                return weakestCharacter;
            else
                return closestCharacter; // Otherwise, return the closest character
        }
    };
};
