#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <stdexcept>
#include <iostream>

using namespace ariel;

TEST_CASE("Adding elements")
{
    MagicalContainer container;
    container.addElement(42);
    CHECK(container.size() == 1);
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    CHECK(container.size() == 4);
}

TEST_CASE("Removing elements")
{
    MagicalContainer container;
    container.addElement(42);
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    container.removeElement(10);
    CHECK(container.size() == 3);
    CHECK_THROWS_AS(container.removeElement(50), std::runtime_error);
    CHECK(container.size() == 3);
}

TEST_CASE("Ascending iterator")
{
    MagicalContainer container;
    container.addElement(42);
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);

    int expected[] = {10, 20, 30, 42};
    int index = 0;
    MagicalContainer::AscendingIterator it(container);
    while (*it != *(it.end()))
    {
        CHECK(*it == expected[index]);
        ++index;
        ++it;
    }
}

TEST_CASE("Side cross iterator")
{
    MagicalContainer container;
    container.addElement(42);
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    int expected[] = {42, 30, 10, 20};
    int index = 0;

    MagicalContainer::SideCrossIterator it(container);
    while (*it != *(it.end()))
    {
        CHECK(*it == expected[index]);
        ++index;
        ++it;
    }
}

TEST_CASE("Prime iterator")
{
    // Creating an instance of MagicalContainer
    MagicalContainer container;

    // Adding four elements to the container
    container.addElement(42);
    container.addElement(10);
    container.addElement(20);
    container.addElement(7);

    // Creating an array of expected values
    int expected[] = {7};
    int index = 0;

    MagicalContainer::PrimeIterator it(container);

    // Iterating over the container using a prime iterator
    while (*it != *(it.end()))
    {
        // Checking if the current value matches the expected value
        CHECK(*it == expected[index]);
        ++index;
        ++it;
    }
}

TEST_CASE("Iterator comparison")
{
    MagicalContainer container;
    container.addElement(42);
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    MagicalContainer::AscendingIterator ascIt1(container);
    MagicalContainer::AscendingIterator ascIt2(container);

    CHECK(ascIt1.begin() == ascIt2.begin());

    MagicalContainer::SideCrossIterator sideIt1(container);
    MagicalContainer::SideCrossIterator sideIt2(container);
    CHECK(sideIt1.begin() == sideIt2.begin());

    MagicalContainer::PrimeIterator primeIt1(container);
    MagicalContainer::PrimeIterator primeIt2(container);
    CHECK(primeIt1 == primeIt2);
    ++ascIt2;
    CHECK(ascIt1 != ascIt2);
    CHECK(ascIt1 < ascIt2);
    CHECK(ascIt2 > ascIt1);
    ++sideIt2;
    CHECK(sideIt1 != sideIt2);
    CHECK(sideIt1 < sideIt2);
    CHECK(sideIt2 > sideIt1);
    ++primeIt2;
    CHECK(primeIt1 != primeIt2);
    CHECK(primeIt1 < primeIt2);
    CHECK(primeIt2 > primeIt1);
}

TEST_CASE("Ascending iterator (negative, positive)")
{
    MagicalContainer container;

    container.addElement(-10);
    container.addElement(20);
    container.addElement(-30);
    container.addElement(40);
    int expected[] = {-30, -10, 20, 40};
    int index = 0;

    MagicalContainer::AscendingIterator it(container);

    while (*it != *(it.end()))
    {
        CHECK(*it == expected[index]);
        ++index;
        ++it;
    }
}
