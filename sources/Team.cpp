#include "Team.hpp"
namespace ariel
{
    Team::Team(Character *leader)
    {
        this->leader = leader;
    }
    Team::~Team()
    {
        delete[] members;
        delete leader;
    }
    void Team::add(Character *new_char) {}
    void Team::attack(Team *other) {}
    int Team::stillAlive() { return 0; }
    void Team::print() {}
};
