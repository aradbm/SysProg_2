#include <iostream>
#include "Ninja.hpp"

namespace ariel
{
    void Ninja::move(Character *other)
    {
        if (isAlive() && other->isAlive())
        {
            Point new_location = Point::moveTowards(getLocation(), other->getLocation(), speed);
            setLocation(new_location);
        }
    }
    void Ninja::slash(Character *other)
    {
        if (!other->isAlive())
            throw std::runtime_error("Cannot slash a dead character.");
        if (!isAlive())
            throw std::runtime_error("Cannot slash with a dead character.");
        if (other == this)
            throw std::runtime_error("Cannot slash yourself.");
        if (distance(other) <= 1 && isAlive() && other->isAlive())
        {
            other->hit(40);
        }
    }
}
