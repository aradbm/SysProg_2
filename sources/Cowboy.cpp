#include <iostream>
#include "Cowboy.hpp"

namespace ariel
{
    void Cowboy::shoot(Character *other)
    {
        if (bullets > 0)
        {
            std::cout << getName() << " shoots " << other->getName() << std::endl;
            bullets--;
            other->hit(10);
        }
        else
        {
            std::cout << getName() << " is out of bullets." << std::endl;
        }
    }

    bool Cowboy::hasboolets()
    {
        return bullets > 0;
    }

    void Cowboy::reload()
    {
        bullets = 6;
        std::cout << getName() << " has reloaded." << std::endl;
    }
}
