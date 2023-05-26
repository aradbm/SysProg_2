#pragma once
#include "Ninja.hpp"
namespace ariel
{
    class OldNinja : public Ninja
    {
    public:
        OldNinja(const std::string &name, const Point &location) : Ninja(name, location, on_speed, on_hp) {}
    };
};