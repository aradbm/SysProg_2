#include <iostream>
#include "Ninja.hpp"

namespace ariel
{
    void Ninja::move(Character *other)
    {
        if (isAlive() && other->isAlive())
        {
            Point::moveTowards(getLocation(), other->getLocation(), speed);
        }
    }
    void Ninja::slash(Character *other)
    {
        if (distance(other) <= 1 && isAlive() && other->isAlive())
        {
            other->hit(40);
        }
    }
}
