#pragma once
#include "Ninja.hpp"
namespace ariel
{
    class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(const string &name, const Point &location) : Ninja(name, location, tn_speed, tn_hp) {}
    };
};