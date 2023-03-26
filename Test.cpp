#include "doctest.h"
#include <stdexcept>
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;
// ------------------- Player tests: -------------------
TEST_CASE("test Player after construct")
{
    Player p1("moshe");
    Player p2("yosi");
    Game game(p1, p2);
    bool v1 = p1.stacksize() == 26;
    bool v2 = p2.stacksize() == 26;
    CHECK(v1);
    CHECK(v2);
    v1 = p1.cardesTaken() == 0;
    v2 = p2.cardesTaken() == 0;
    CHECK(v1);
    CHECK(v2);
}
TEST_CASE("test player and game before game constructed")
{
    Player p1("moshe");
    Player p2("yosi");
    CHECK_THROWS(p1.cardesTaken());
    CHECK_THROWS(p1.stacksize());
    CHECK_THROWS(Game(p1, p1)); // cant create a game with the same player
    Game game(p1, p2);
    CHECK_THROWS(Game(p1, p2)); // cant create a game with 2 different players.
}
// ------------------- Game tests: -------------------
TEST_CASE("check playturn")
{
    Player p1("moshe");
    Player p2("yosi");
    Game game(p1, p2);
    game.playTurn();
    CHECK(p1.stacksize() < 26);
    CHECK(p2.stacksize() < 26);
    bool v1 = p1.cardesTaken() > 0 || p2.cardesTaken() > 0;
    CHECK(v1);
    v1 = p1.stacksize() + p2.stacksize() + p1.cardesTaken() + p2.cardesTaken() == 52;
    CHECK(v1);
}
TEST_CASE("check overall stacksize mid game")
{
    Player p1("moshe");
    Player p2("yosi");
    Game game(p1, p2);
    bool v1 = p1.stacksize() + p2.stacksize() + p1.cardesTaken() + p2.cardesTaken() == 52;
    CHECK(v1);
    int i = 0;
    while (p1.stacksize() != 0 && p2.stacksize() != 0 && (i++ < 26))
    {
        game.playTurn();
        v1 = p1.stacksize() + p2.stacksize() + p1.cardesTaken() + p2.cardesTaken() == 52;
        CHECK(v1);
    }
    v1 = p1.stacksize() == 0 && p2.stacksize() == 0;
    CHECK(v1);
}
TEST_CASE("check playAll func")
{
    Player p1("moshe");
    Player p2("yosi");
    Game game(p1, p2);
    // checks prints for a game that has not started yet
    CHECK_THROWS(game.printLastTurn());
    CHECK_THROWS(game.printWiner());
    CHECK_THROWS(game.printLog());
    game.playAll();
    bool v1 = p1.stacksize() + p2.stacksize() + p1.cardesTaken() + p2.cardesTaken() == 52;
    CHECK(v1);
    CHECK_THROWS(game.playAll());
    CHECK_THROWS(game.playTurn());
}