#include <iostream>
#include <math.h>
#include "Point.hpp"
#include "Character.hpp"
namespace ariel
{
    Point::Point(double lat, double log) : lat(lat), lon(log) {}

    double Point::getX()
    {
        return lat;
    }

    double Point::getY()
    {
        return lon;
    }

    double Point::distance(Point other)
    {
        return 0.0;
    }

    void Point::print()
    {
    }
};
