#pragma once
#include "Ninja.hpp"
namespace ariel
{
    class YoungNinja : public Ninja
    {
    public:
        YoungNinja(const string &name, const Point &location) : Ninja(name, location, yn_speed, yn_hp) {}
    };
};