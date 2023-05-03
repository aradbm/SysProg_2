#include "doctest.h"
#include <stdexcept>
#include "sources/Team.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("Test Point")
{
    Point p1(1, 2);
    Point p2(3, 4);
    CHECK(p1.getX() == 1);
    CHECK(p1.getY() == 2);
    CHECK(p1.distance(p2) == 2 * sqrt(2));
}

TEST_CASE("Test Cowboy")
{
    Point p1(1, 2);
    Point p2(3, 4);
    Cowboy c1("c1", p1);
    Cowboy c2("c2", p2);
    CHECK(c1.getName() == "c1");
    CHECK(c1.getLocation().getX() == 1);
    CHECK(c1.getLocation().getY() == 2);
    CHECK(c1.isAlive() == true);
    CHECK(c1.distance(c2) == 2 * sqrt(2));
    c1.hit(c2);
    CHECK(c2.isAlive() == false);
    CHECK(c1.isAlive() == true);
    CHECK(c1.hasBullets() == false);
    c1.reload();
    CHECK(c1.hasBullets() == true);
    c1.shoot(&c2);
    CHECK(c2.isAlive() == false);
    CHECK(c1.hasBullets() == false);
}

TEST_CASE("Test Ninjas")
{
    Point p1(1, 2);
    Point p2(3, 4);
    OldNinja n1("n1", p1);
    YoungNinja n2("n2", p2);
    TrainedNinja n3("n3", p1);
    CHECK(n1.getName() == "n1");
    CHECK(n1.getLocation().getX() == 1);
    CHECK(n1.getLocation().getY() == 2);
    CHECK(n1.isAlive() == true);
    CHECK(n1.distance(n2) == 2 * sqrt(2));
    n1.hit(n2);
    CHECK(n2.isAlive() == false);
    CHECK(n1.isAlive() == true);
}

TEST_CASE("Test Teams")
{
    Point p1(1, 2);
    Point p2(3, 4);
    Cowboy c1("c1", p1);
    Cowboy c2("c2", p2);
    OldNinja n1("n1", p1);
    YoungNinja n2("n2", p2);
    Team t1(&c1);
    Team t2(&n1);
    CHECK(t1.stillAlive() == 1);
    CHECK(t2.stillAlive() == 1);
    t1.add(&c2);
    t2.add(&n2);
    CHECK(t1.stillAlive() == 2);
    CHECK(t2.stillAlive() == 2);
    t1.attack(&t2);
    CHECK(t1.stillAlive() == 2);
    CHECK(t2.stillAlive() == 0);
    t1.print();
    t2.print();
}