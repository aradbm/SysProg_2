#include <iostream>
#include "Cowboy.hpp"

namespace ariel
{
    void Cowboy::shoot(Character *other)
    {
        if (!other->isAlive())
            throw std::runtime_error("Cannot shoot a dead character.");
        if (!isAlive())
            throw std::runtime_error("Cannot shoot with a dead character.");
        if (other == this)
            throw std::runtime_error("Cannot shoot yourself.");
        if (bullets > 0)
        {
            bullets--;
            other->hit(10);
        }
    }

    bool Cowboy::hasboolets() { return bullets > 0; }

    void Cowboy::reload()
    {
        if (!isAlive())
            throw std::runtime_error("Cannot reload with a dead character.");
        bullets = 6;
    }
}
