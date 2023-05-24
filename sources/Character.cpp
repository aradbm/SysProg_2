#include <iostream>
#include <cmath>
#include "Character.hpp"

namespace ariel
{
    Character::Character(string name, int health, const Point &location)
        : name(name), health(health), location(location)
    {
        this->inGame = false;
    }

    string Character::print()
    {
        return "Character: " + name + "\nHealth: " + to_string(health) +
               "\nLocation: (" + to_string(location.getX()) + ", " + to_string(location.getY()) + ")";
    }

    bool Character::isAlive()
    {
        return health > 0;
    }

    double Character::distance(Character *other)
    {
        return location.distance(other->getLocation());
    }

    void Character::hit(double value)
    {
        if (value < 0)
            throw std::invalid_argument("Negative value is not allowed.");
        if (!isAlive())
            throw std::runtime_error("Cannot hit a dead character.");
        this->health -= value;
    }
}