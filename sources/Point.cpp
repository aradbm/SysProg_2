#include "Point.hpp"
#include <cmath>

namespace ariel
{

    Point::Point(double lat, double lon) : lat(lat), lon(lon) {}
    double Point::getX() const
    {
        return lat;
    }

    double Point::getY() const
    {
        return lon;
    }

    double Point::distance(const Point &other) const
    {
        double x_diff = other.getX() - lat;
        double y_diff = other.getY() - lon;
        return std::sqrt(x_diff * x_diff + y_diff * y_diff);
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
            throw std::invalid_argument("Negative distance is not allowed.");
        }

        double x3 = x1 + (dist * (x2 - x1)) / distance;
        double y3 = y1 + (dist * (y2 - y1)) / distance;

        return Point(x3, y3);
    }
}
