#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <math.h>
namespace ariel
{
    class Point
    {
    private:
        double lat;
        double lon;

    public:
        Point(double lat, double lon);
        double getX();
        double getY();

        double distance(Point other);
        void print();
        Point moveTowards(Point other, double dist);
    };
};

#endif