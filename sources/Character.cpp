#include <iostream>
#include <string>
#include <math.h>
#include "Point.hpp"

using namespace std;
namespace ariel
{
    class Character
    {
    private:
        std::string name;
        int health;
        Point &location;

    public:
        Character(std::string name, int health, Point location)
            : name(name), health(health), location(location) {}

        std::string getName() const { return name; }
        Point getLocation() const { return location; }

        std::string print() const
        {
            return "Character: " + name + "\nHealth: " + std::to_string(health) +
                   "\nLocation: (" + std::to_string(location.getX()) + ", " + std::to_string(location.getY()) + ")";
        }

        bool isAlive() const { return health > 0; }

        double Character::distance(Character *other)
        {
            return location.distance(other->getLocation());
        }

        void hit(double value)
        {
            if (value < 0)
            {
                throw std::invalid_argument("Negative value is not allowed.");
            }
            std::cout << name << " was hit with " << value << " damage." << std::endl;
        }
    };
}
