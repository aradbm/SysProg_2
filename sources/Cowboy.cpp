#include "Cowboy.hpp"
namespace ariel
{
    void Cowboy::hit(Character &other) {}
    double Cowboy::distance(Character &other) { return 0.0; }
    void Cowboy::shoot(Character *other) {}
    bool Cowboy::hasBullets() { return false; }
    void Cowboy::reload() {}
};
