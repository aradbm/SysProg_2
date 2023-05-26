#pragma once
#include <iostream>
#include <cmath>

namespace ariel
{

    class Point
    {
    private:
        double lat;
        double lon;

    public:
        Point(double lat, double lon);
        double getX() const;
        double getY() const;

        double distance(const Point &other) const;
        void print() const;
        static Point moveTowards(const Point &point1, const Point &point2, double dist);
    };

}
