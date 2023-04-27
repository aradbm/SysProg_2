#include "Fraction.hpp"

namespace ariel
{
    Fraction::Fraction(int divident, int divisor)
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

    std::ostream &operator<<(std::ostream &o_stream, const Fraction &frac)
    {
        return o_stream;
    }

    std::ostream &operator<<(std::ostream &o_stream, bool frac)
    {
        return o_stream;
    }

    std::istream &operator>>(std::istream &i_stream, Fraction &frac)
    {
        return i_stream;
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