#include "doctest.h"
#include <stdexcept>
#include "sources/Fraction.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Test arithmetic operators")
{
    Fraction a(2, 5), b(4, 9);
    CHECK(a + b == Fraction(58, 45));
    CHECK(a - b == Fraction(-14, 45));
    CHECK(a / b == Fraction(18, 20));
    CHECK(a * b == Fraction(8, 45));
    CHECK(1.7 * b == Fraction(68, 45));
    CHECK(a + 2.123 == Fraction(337, 250));
    Fraction c = a + b - 1;
    CHECK(c++ == Fraction(13, 9));
    CHECK(--c == Fraction(4, 45));
    c = c - Fraction(1, 9);
    CHECK(c == Fraction(11, 45));
    c = c - Fraction(11, 45);
    CHECK(c == Fraction(0, 1));
}

TEST_CASE("Test comparison operators")
{
    Fraction a(2, 5), b(4, 9);
    CHECK(a >= b);
    CHECK(a > 0.8);
    CHECK(a != b);
    CHECK(a < b);
    CHECK(a <= b);
}

TEST_CASE("Test input")
{
    Fraction a(2, 5), b(4, 9);
    cout << a << endl;
    CHECK(a == Fraction(2, 5));
    cout << b << endl;
    CHECK(b == Fraction(4, 9));
}

TEST_CASE("Fraction always at minimal value")
{
    Fraction a(5, 5), b(4, 9);
    CHECK(a == Fraction(1, 1));
    CHECK(b == Fraction(4, 9));
    Fraction c = a + b;
    CHECK(c == Fraction(14, 9));
}

TEST_CASE("Test except dividing in 0")
{
    CHECK_THROWS(Fraction(1, 0));
    CHECK_NOTHROW(Fraction(1, 1) - Fraction(1, 1));
}
