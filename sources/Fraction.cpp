#include "Fraction.hpp"
#include <iostream>
#include <stdexcept>
#include <numeric>

int maxInt = 2147483647;
int minInt = -2147483648;
namespace ariel
{
    Fraction::Fraction() : divident(0), divisor(1) {}
    Fraction::Fraction(int divident, int divisor)
    {
        if (divisor == 0)
            throw std::invalid_argument("divideing by 0!");
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
            throw std::invalid_argument("divideing by 0!");
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
            throw std::overflow_error("cant +");
        if (num1 != 0 && num2 != 0 && num1 * num2 < minInt)
            throw std::overflow_error("cant +");
        int commonDivisor = this->divisor * other.divisor;
        int newDivident = this->divident * other.divisor + other.divident * this->divisor;
        return Fraction(newDivident, commonDivisor);
    }

    Fraction Fraction::operator-(const Fraction &other) const
    {
        if ((double)(this->divisor) * other.divisor > (double)(maxInt))
            throw std::overflow_error("cant -");

        if ((double)(this->divident) * other.divisor - (double)(other.divident) * this->divisor > (double)(maxInt))
            throw std::overflow_error("cant -");
        int commonDivisor = this->divisor * other.divisor;
        int newDivident = this->divident * other.divisor - other.divident * this->divisor;
        return Fraction(newDivident, commonDivisor);
    }

    Fraction Fraction::operator*(const Fraction &other) const
    {
        if (other.divident == 0 || this->divident == 0)
            return Fraction(0, 1);
        if ((double)(this->divident) * other.divident > (double)(maxInt) ||
            (double)(this->divisor) * other.divisor > (double)(maxInt))
            throw std::overflow_error("cant *");
        int newDivident = this->divident * other.divident;
        int newDivisor = this->divisor * other.divisor;
        Fraction result(newDivident, newDivisor);
        result.reduce();
        return result;
    }

    Fraction Fraction::operator/(const Fraction &other) const
    {
        if (other.divident == 0)
            throw std::overflow_error("cant /");
        if ((double)(this->divident) * other.divisor > (double)(maxInt) ||
            (double)(this->divisor) * other.divident > (double)(maxInt))
            throw std::overflow_error("cant /");
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
        float num1 = (float)this->divident / this->divisor;
        float num2 = (float)other.divident / other.divisor;
        return std::abs(num1 - num2) < 0.001; // check if the difference is less than 0.001 like needed
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
        if (i_stream.peek() == '.')
            throw std::runtime_error("Invalid input.");
        i_stream.ignore(1); // Ignore the / or ,
        int divisor;
        i_stream >> divisor;
        if (divisor == 0)
            throw std::runtime_error("divideing by 0!");
        frac.divisor = divisor;
        frac.reduce();
        if (i_stream.fail())
            throw std::runtime_error("Invalid input.");
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