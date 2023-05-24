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
        double xDiff = other.getX() - lat;
        double yDiff = other.getY() - lon;
        return std::sqrt(xDiff * xDiff + yDiff * yDiff);
    }

    void Point::print() const
    {
        std::cout << "(" << lat << ", " << lon << ")" << std::endl;
    }
    Point Point::moveTowards(const Point &point1, const Point &point2, double dist)
    {
        if (dist < 0)
            throw std::invalid_argument("negative");

        double x_diff = point2.getX() - point1.getX();
        double y_diff = point2.getY() - point1.getY();
        double distance = std::sqrt(x_diff * x_diff + y_diff * y_diff);

        if (distance <= dist)
            return point2;

        double ratio = dist / distance;
        double x = point1.getX() + ratio * x_diff;
        double y = point1.getY() + ratio * y_diff;

        return Point(x, y);
    }
}
