#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>

namespace ariel
{
    class Fraction
    {
    private:
        int numerator;
        int denominator;

    public:
        Fraction(int n, int d);
        Fraction(float num);

        Fraction operator+(const Fraction &other) const;
        Fraction operator-(const Fraction &other) const;
        Fraction operator*(const Fraction &other) const;
        Fraction operator/(const Fraction &other) const;
        Fraction operator++();
        Fraction operator++(int);
        Fraction operator--();
        Fraction operator--(int);
        bool operator==(const Fraction &other) const;
        bool operator!=(const Fraction &other) const;
        bool operator<(const Fraction &other) const;
        bool operator>(const Fraction &other) const;
        bool operator<=(const Fraction &other) const;
        bool operator>=(const Fraction &other) const;
        friend std::ostream &operator<<(std::ostream &os, const Fraction &frac);
        friend std::ostream &operator<<(std::ostream &os, bool frac);
        friend std::istream &operator>>(std::istream &is, Fraction &frac);
        friend Fraction operator+(const float &num, const Fraction &other);
        friend Fraction operator-(const float &num, const Fraction &other);
        friend Fraction operator*(const float &num, const Fraction &other);
        friend Fraction operator/(const float &num, const Fraction &other);
        friend bool operator==(const float &num, const Fraction &other);
        friend bool operator!=(const float &num, const Fraction &other);
        friend bool operator<(const float &num, const Fraction &other);
        friend bool operator>(const float &num, const Fraction &other);
        friend bool operator<=(const float &num, const Fraction &other);
        friend bool operator>=(const float &num, const Fraction &other);
    };
}

#endif
