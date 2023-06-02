#include "MagicalContainer.hpp"
#include <iostream>
#include "doctest.h"
using namespace std;
using namespace ariel;

TEST_CASE("Sum of Elements")
{
    MagicalContainer container;
    container.addElement(2);
    container.addElement(4);
    container.addElement(6);

    CHECK(container.size() == 3);

    MagicalContainer::AscendingIterator ascendingIter(container);
    int sum = 0;
    for (int *ptr = ascendingIter.begin(); ptr != ascendingIter.end(); ++ptr)
    {
        sum += *ptr;
    }

    CHECK(sum == 12);
    CHECK(sum != 10);
    CHECK(sum > 0);
}

TEST_CASE("Count Prime Numbers")
{
    MagicalContainer container;

    container.addElement(3);
    container.addElement(4);
    container.addElement(7);
    container.addElement(9);

    CHECK(container.size() == 4);

    MagicalContainer::PrimeIterator primeIter(container);
    int count = 0;
    for (int *ptr = primeIter.begin(); ptr != primeIter.end(); ++ptr)
    {
        ++count;
    }

    CHECK(count == 2);
    CHECK(count != 3);
    CHECK(count > 0);
    CHECK(count <= 2);
}

TEST_CASE("Add and Remove Elements")
{
    MagicalContainer container;

    container.addElement(2);
    container.addElement(4);
    container.addElement(6);
    container.removeElement(4);
    container.addElement(8);

    CHECK(container.size() == 3);
}

TEST_CASE("Ascending Iterator with Negative Numbers")
{
    MagicalContainer container;

    container.addElement(-5);
    container.addElement(-10);
    container.addElement(-15);

    MagicalContainer::AscendingIterator ascendingIter(container);

    int sum = 0;
    for (int *ptr = ascendingIter.begin(); ptr != ascendingIter.end(); ++ptr)
    {
        sum += *ptr;
    }

    CHECK(sum == -30);
    CHECK(sum != 0);
    CHECK(sum < 0);
}

TEST_CASE("Remove Nonexistent Element")
{
    MagicalContainer container;

    container.addElement(2);
    container.addElement(4);
    container.addElement(6);

    container.removeElement(8);

    CHECK(container.size() == 3);
}

TEST_CASE("Ascending Iterator")
{
    MagicalContainer container;

    container.addElement(-5);
    container.addElement(-10);
    container.addElement(-15);

    CHECK(container.size() == 3);
    CHECK(container.size() != 0);

    MagicalContainer::AscendingIterator ascendingIter(container);

    int sum = 0;
    for (int *ptr = ascendingIter.begin(); ptr != ascendingIter.end(); ++ptr)
    {
        sum += *ptr;
    }

    CHECK(sum == -30);
    CHECK(sum != 0);
    CHECK(sum < 0);
    CHECK(ascendingIter.begin() != nullptr);
    CHECK(ascendingIter.end() != nullptr);
    CHECK(container.size() >= 2);
    CHECK(container.size() < 5);
    CHECK(container.size() > 0);
}
