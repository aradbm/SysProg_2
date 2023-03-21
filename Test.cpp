#include "doctest.h"
#include <stdexcept>
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;
// ------------------- Player tests: -------------------
TEST_CASE("test player constructor")
{
    Player p1("moshe");
    Player p2("yosi");
    bool v1 = p1.stacksize() == 26;
    bool v2 = p2.stacksize() == 26;
    CHECK(v1);
    CHECK(v2);
}
// ------------------- Game tests: -------------------
TEST_CASE("check overall stacksize mid game")
{
    Player p1("moshe");
    Player p2("yosi");
    Game game(p1, p2);
    bool v1 = p1.stacksize() + p2.stacksize() == 52;
    for (int i = 0; i < 5; i++)
    {
        game.playTurn();
        CHECK(v1);
    }
}
TEST_CASE("check playAll func")
{
    Player p1("moshe");
    Player p2("yosi");
    Game game(p1, p2);
    game.playAll();
    bool v1 = p1.stacksize() == 0 || p2.stacksize() == 0;
    bool v2 = p1.stacksize() + p2.stacksize() == 52;
    CHECK(v1);
    CHECK(v2);
}