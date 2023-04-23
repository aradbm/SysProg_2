#include "Fraction.hpp"

namespace ariel
{
    Fraction::Fraction(int n, int d)
    {
    }

    Fraction::Fraction(float num)
    {
    }

    Fraction Fraction::operator+(const Fraction &other) const
    {
        return other;
    }

    Fraction Fraction::operator-(const Fraction &other) const
    {
        return other;
    }

    Fraction Fraction::operator*(const Fraction &other) const
    {
        return other;
    }

    Fraction Fraction::operator/(const Fraction &other) const
    {
        return other;
    }

    Fraction Fraction::operator++()
    {
        return *this;
    }

    Fraction Fraction::operator++(int)
    {
        return *this;
    }

    Fraction Fraction::operator--()
    {
        return *this;
    }

    Fraction Fraction::operator--(int)
    {
        return *this;
    }

    bool Fraction::operator==(const Fraction &other) const
    {
        return true;
    }

    bool Fraction::operator!=(const Fraction &other) const
    {
        return true;
    }

    bool Fraction::operator<(const Fraction &other) const
    {
        return true;
    }

    bool Fraction::operator>(const Fraction &other) const
    {
        return true;
    }

    bool Fraction::operator<=(const Fraction &other) const
    {
        return true;
    }

    bool Fraction::operator>=(const Fraction &other) const
    {
        return true;
    }

    std::ostream &operator<<(std::ostream &os, const Fraction &frac)
    {
        return os;
    }

    std::ostream &operator<<(std::ostream &os, bool frac)
    {
        return os;
    }

    std::istream &operator>>(std::istream &is, Fraction &frac)
    {
        return is;
    }

    Fraction operator+(const float &num, const Fraction &other)
    {
        return other;
    }

    Fraction operator-(const float &num, const Fraction &other)
    {
        return other;
    }

    Fraction operator*(const float &num, const Fraction &other)
    {
        return other;
    }

    Fraction operator/(const float &num, const Fraction &other)
    {
        return other;
    }

    bool operator==(const float &num, const Fraction &other)
    {
        return true;
    }

    bool operator!=(const float &num, const Fraction &other)
    {
        return true;
    }

    bool operator<(const float &num, const Fraction &other)
    {
        return true;
    }

    bool operator>(const float &num, const Fraction &other)
    {
        return true;
    }

    bool operator<=(const float &num, const Fraction &other)
    {
        return true;
    }
    bool operator>=(const float &num, const Fraction &other)
    {
        return true;
    }
}