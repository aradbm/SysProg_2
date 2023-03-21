#include <iostream>
using namespace std;
namespace ariel
{

    class Player
    {
        string name;

    public:
        player(string name);
        int stacksize();
        int cardesTaken();
    };

}