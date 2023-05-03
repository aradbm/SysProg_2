#include "doctest.h"
#include <stdexcept>
#include "sources/Team.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("Test Team")
{
    Point a(32.3, 44), b(1.3, 3.5);
    Cowboy tom = Cowboy("Tom", a);
    OldNinja sushi = OldNinja("sushi", b);
    Team a1(tom);
    // a1.add(YoungNinja("Yogi", Point(64, 57)));
    Team b2(sushi);
    // b2.add(TrainedNinja("Hikari", Point(12, 81)));
}