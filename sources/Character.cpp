#include "Character.hpp"

namespace ariel
{

    Character::Character(string name, int health, Point location) : name(name), health(health), location(location)
    {
    }
    string Character::getName() { return ""; }
    Point Character::getLocation() { return Point(0, 0); }

    string Character::print()
    {
        return "";
    }

    bool Character::isAlive() { return false; }
    double Character::distance(Character &other) { return 0.0; }
    void Character::hit(Character &other) {}
};
