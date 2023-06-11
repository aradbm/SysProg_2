#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include "sources/Team.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Test Point class")
{
    Point points[3] = {Point(1, 2), Point(3, 4), Point(5, 6)};
    for (int i = 0; i < 3; i++)
    {
        CHECK(points[i].getX() == i * 2 + 1);
        CHECK(points[i].getY() == i * 2 + 2);
    }

    CHECK_EQ(points[0].distance(points[1]), 2.8284271247461903);
    CHECK_EQ(points[0].distance(points[2]), 5.656854249492381);
    CHECK_EQ(points[1].distance(points[2]), 2.8284271247461903);
    CHECK_NOTHROW(Point::moveTowards(points[0], points[1], 1));
}

TEST_CASE("Test Characters creation")
{
    Cowboy c1("Cowboy", Point(1, 2));
    YoungNinja c2("Young Ninja", Point(3, 4));
    TrainedNinja c3("Trained Ninja", Point(5, 6));
    OldNinja c4("Old Ninja", Point(7, 8));

    Character *chars[4] = {&c1, &c2, &c3, &c4};
    string names[4] = {"Cowboy", "Young Ninja", "Trained Ninja", "Old Ninja"};
    for (int i = 0; i < 4; i++)
    {
        CHECK_EQ(chars[i]->getName(), names[i]);
        CHECK_EQ(chars[i]->getLocation().getX(), i * 2 + 1);
        CHECK_EQ(chars[i]->getLocation().getY(), i * 2 + 2);
        CHECK_EQ(chars[i]->isAlive(), true);
    }

    CHECK_EQ(c1.print(), "Name: C(Cowboy), HP: 100, Location: (1,2)");
    CHECK_EQ(c2.print(), "Name: Y(Young Ninja), HP: 100, Location: (3,4)");
    CHECK_EQ(c3.print(), "Name: T(Trained Ninja), HP: 120, Location: (5,6)");
    CHECK_EQ(c4.print(), "Name: O(Old Ninja), HP: 150, Location: (7,8)");
}

TEST_CASE("Test 5: Health after attack")
{
    Cowboy c1("Cowboy", Point(0, 0));
    YoungNinja c2("Young Ninja", Point(0, 1));

    int initial_c1_hp = c1.getHealth();
    int initial_c2_hp = c2.getHealth();

    CHECK_NOTHROW(c1.shoot(&c2));
    CHECK_LT(c2.getHealth(), initial_c2_hp); // After the attack, c2's HP should be less than initial.

    CHECK_NOTHROW(c2.slash(&c1));
    CHECK_LT(c1.getHealth(), initial_c1_hp); // After the attack, c1's HP should be less than initial.
}

TEST_CASE("Test smart team")
{
    Point a(32.3, 44), b(1.3, 3.5);
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    tom->shoot(sushi);
    cout << tom->print() << endl;

    sushi->move(tom);
    sushi->slash(tom);

    SmartTeam team_A(tom);
    team_A.add(new YoungNinja("Yogi", Point(64, 57)));

    Team team_B(sushi);
    team_B.add(new TrainedNinja("Hikari", Point(12, 81)));

    CHECK_EQ(team_A.stillAlive(), 2);
    CHECK_EQ(team_B.stillAlive(), 2);

    while (team_A.stillAlive() > 0 && team_B.stillAlive() > 0)
    {
        team_A.attack(&team_B);
        team_B.attack(&team_A);
        team_A.print();
        team_B.print();
    }
    bool team_A_won = team_A.stillAlive() > 0;
    bool team_B_won = team_B.stillAlive() > 0;
    bool team_won = team_A_won || team_B_won;
    CHECK_EQ(team_won, true);
}