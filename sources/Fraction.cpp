#include "Fraction.hpp"
#include <iostream>
#include <stdexcept>
#include <numeric>
#include <limits>

int maxInt = std::numeric_limits<int>::max();
int minInt = std::numeric_limits<int>::min();
namespace ariel
{

    Fraction::Fraction() : divident(0), divisor(1) {}

    Fraction::Fraction(int divident, int divisor)
    {
        if (divisor == 0)
        {
            throw std::invalid_argument("Divisor cannot be zero.");
        }

        this->divident = divident;
        this->divisor = divisor;
        reduce();
    }

    Fraction::Fraction(float num)
    {
        this->divident = (int)(num * 1000);
        this->divisor = 1000;
        reduce();
        if (divisor == 0)
        {
            throw std::invalid_argument("Divisor cannot be zero.");
        }
    }

    int Fraction::getNumerator() const
    {
        return divident;
    }

    int Fraction::getDenominator() const
    {
        return divisor;
    }

    void Fraction::reduce()
    {
        int gcd = std::gcd(divident, divisor);
        divident /= gcd;
        divisor /= gcd;

        if (divisor < 0)
        {
            divident *= -1;
            divisor *= -1;
        }
    }

    Fraction Fraction::operator+(const Fraction &other) const
    {
        long long num1 = (long long)(this->divident) / this->divisor;
        long long num2 = (long long)(other.divident) / other.divisor;
        if (num1 != 0 && num2 != 0 && num1 * num2 > maxInt)
        {
            throw std::overflow_error("Cannot add.");
        }
        if (num1 != 0 && num2 != 0 && num1 * num2 < minInt)
        {
            throw std::overflow_error("Cannot add.");
        }

        int commonDivisor = this->divisor * other.divisor;
        int newDivident = this->divident * other.divisor + other.divident * this->divisor;

        return Fraction(newDivident, commonDivisor);
    }

    Fraction Fraction::operator-(const Fraction &other) const
    {
        long long num1 = (long long)(this->divident) / this->divisor;
        long long num2 = (long long)(other.divident) / other.divisor;
        if (num1 != 0 && num2 != 0 && num1 * num2 > maxInt)
        {
            throw std::overflow_error("Cannot subtract.");
        }
        if (num1 != 0 && num2 != 0 && num1 * num2 < minInt)
        {
            throw std::overflow_error("Cannot subtract.");
        }

        int commonDivisor = this->divisor * other.divisor;
        int newDivident = this->divident * other.divisor - other.divident * this->divisor;
        return Fraction(newDivident, commonDivisor);
    }

    Fraction Fraction::operator*(const Fraction &other) const
    {
        if (other.divident == 0 || this->divident == 0)
        {
            return Fraction(0, 1);
        }
        if (this->divident == maxInt || other.divident == maxInt)
        {
            throw std::overflow_error("Cannot multiply.");
        }
        long long num1 = (long long)(this->divident) / this->divisor;
        long long num2 = (long long)(other.divident) / other.divisor;
        if (num1 != 0 && num2 != 0 && num1 * num2 > maxInt)
        {
            throw std::overflow_error("Cannot multiply.");
        }
        if (num1 != 0 && num2 != 0 && num1 * num2 < minInt)
        {
            throw std::overflow_error("Cannot multiply.");
        }

        int newDivident = this->divident * other.divident;
        int newDivisor = this->divisor * other.divisor;
        Fraction result(newDivident, newDivisor);
        result.reduce();
        return result;
    }

    Fraction Fraction::operator/(const Fraction &other) const
    {
        if (other.divident == 0)
        {
            throw std::overflow_error("Cannot divide by zero.");
        }
        int newDivident = this->divident * other.divisor;
        int newDivisor = this->divisor * other.divident;
        return Fraction(newDivident, newDivisor);
    }

    Fraction Fraction::operator++()
    {
        this->divident += this->divisor;
        return *this;
    }

    Fraction Fraction::operator++(int)
    {
        Fraction temp(*this);
        this->divident += this->divisor;
        return temp;
    }

    Fraction Fraction::operator--()
    {
        this->divident -= this->divisor;
        return *this;
    }

    Fraction Fraction::operator--(int)
    {
        Fraction temp(*this);
        this->divident -= this->divisor;
        return temp;
    }

    bool Fraction::operator==(const Fraction &other) const
    {
        return this->divident * other.divisor == other.divident * this->divisor;
    }

    bool Fraction::operator!=(const Fraction &other) const
    {
        return !(*this == other);
    }

    bool Fraction::operator<(const Fraction &other) const
    {
        double thisDouble = (double)(this->divident) / this->divisor;
        double otherDouble = (double)(other.divident) / other.divisor;
        return thisDouble < otherDouble;
    }

    bool Fraction::operator>(const Fraction &other) const
    {
        return !(*this < other) && !(*this == other);
    }

    bool Fraction::operator<=(const Fraction &other) const
    {
        return *this < other || *this == other;
    }

    bool Fraction::operator>=(const Fraction &other) const
    {
        return *this > other || *this == other;
    }

    std::ostream &operator<<(std::ostream &o_stream, const Fraction &frac)
    {
        o_stream << frac.divident << "/" << frac.divisor;
        return o_stream;
    }

    std::istream &operator>>(std::istream &i_stream, Fraction &frac)
    {
        i_stream >> frac.divident;
        i_stream.ignore(1); // Ignore the '/' character
        int divisor;
        i_stream >> divisor;
        if (divisor == 0)
        {
            throw std::runtime_error("Divisor cannot be zero.");
        }
        frac.divisor = divisor;
        frac.reduce();
        if (i_stream.fail())
        {
            throw std::runtime_error("Invalid input.");
        }
        return i_stream;
    }
    Fraction operator+(const float &num, const Fraction &other)
    {
        Fraction floatFrac(num);
        return floatFrac + other;
    }

    Fraction operator-(const float &num, const Fraction &other)
    {
        Fraction floatFrac(num);
        return floatFrac - other;
    }

    Fraction operator*(const float &num, const Fraction &other)
    {
        // check not overflow
        Fraction floatFrac(num);
        return floatFrac * other;
    }

    Fraction operator/(const float &num, const Fraction &other)
    {
        Fraction floatFrac(num);
        return floatFrac / other;
    }

    bool operator==(const float &num, const Fraction &other)
    {
        Fraction floatFrac(num);
        return floatFrac == other;
    }

    bool operator!=(const float &num, const Fraction &other)
    {
        Fraction floatFrac(num);
        return floatFrac != other;
    }

    bool operator<(const float &num, const Fraction &other)
    {
        Fraction floatFrac(num);
        return floatFrac < other;
    }

    bool operator>(const float &num, const Fraction &other)
    {
        Fraction floatFrac(num);
        return floatFrac > other;
    }

    bool operator<=(const float &num, const Fraction &other)
    {
        Fraction floatFrac(num);
        return floatFrac <= other;
    }

    bool operator>=(const float &num, const Fraction &other)
    {
        Fraction floatFrac(num);
        return floatFrac >= other;
    }

}