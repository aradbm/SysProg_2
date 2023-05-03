#ifndef NINJA_HPP
#define NINJA_HPP

#include <iostream>
#include <string>

namespace ariel
{

    class Ninja : public Character
    {
    private:
        int speed;

    public:
        Ninja(string name, Point location, int speed) : Character(name, 100, location) {}
        void print();
        bool isAlive();
        double distance(Character &other);
        void hit(Character &other);

        void move(Character &other);
        void slash(Character &other);
    };

    class OldNinja : public Ninja
    {
    public:
    };

    class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(string name, Point location);
        void print();
        bool isAlive();
        double distance(Character &other);
        void hit(Character &other);

        void move(Character &other);
        void slash(Character &other);
    };

    class YoungNinja : public Ninja
    {

    public:
        YoungNinja(string name, Point location) : Ninja(name, location, 14) {}
    };

};

#endif