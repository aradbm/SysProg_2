#include <iostream>
#include <cmath>
#include "Point.hpp"
#include "Character.hpp"

namespace ariel
{

    Point::Point(double lat, double lon) : lat(lat), lon(lon) {}
    double Point::getX() const { return lat; }
    double Point::getY() const { return lon; }
    double Point::distance(const Point &other) const
    {
        return std::sqrt((other.getX() - lat) * (other.getX() - lat) + (other.getY() - lon) * (other.getY() - lon));
    }

    void Point::print() const
    {
        std::cout << "(" << lat << ", " << lon << ")" << std::endl;
    }

    Point Point::moveTowards(const Point &point1, const Point &point2, double dist)
    {
        double x1 = point1.getX();
        double y1 = point1.getY();
        double x2 = point2.getX();
        double y2 = point2.getY();
        double distance = point1.distance(point2);

        if (dist < 0)
        {
            throw std::invalid_argument("cant get negative number");
        }

        double x3 = x1 + (dist * (x2 - x1)) / distance;
        double y3 = y1 + (dist * (y2 - y1)) / distance;

        return Point(x3, y3);
    }

} // namespace ariel
