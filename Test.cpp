#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;
TEST_CASE("test1: ")
{
    Player p1("moshe");
    Player p2("yosi");
    Game game(p1, p2);
    for (int i = 0; i < 5; i++)
    {
        game.playTurn();
    }
    CHECK(p1.stacksize() == p2.stacksize());
}