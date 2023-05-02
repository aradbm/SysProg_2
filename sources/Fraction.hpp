#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>

namespace ariel
{
    class Fraction
    {
    private:
        int divident;
        int divisor;

    public:
        Fraction();
        Fraction(int divident, int divisor);
        Fraction(float num);

        void reduce();
        int getNumerator() const;
        int getDenominator() const;
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
        friend std::ostream &operator<<(std::ostream &o_stream, const Fraction &frac);
        friend std::ostream &operator<<(std::ostream &o_stream, bool frac);
        friend std::istream &operator>>(std::istream &i_stream, Fraction &frac);
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
