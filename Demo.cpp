#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

#include "sources/Team.hpp" //no need for other includes
using namespace ariel;

int main()
{
   Point a(32.3, 44), b(1.3, 3.5);
   assert(a.distance(b) == b.distance(a));
   Cowboy tom = Cowboy("Tom", a);
   OldNinja sushi = OldNinja("sushi", b);
   tom.shoot(sushi);
   // cout << tom.print() << endl;

   sushi.move(tom);
   sushi.slash(tom);

   Team a1(tom);
   a1.add(YoungNinja("Yogi", Point(64, 57)));

   // Team b(&tom); should throw tom is already in team a

   Team b2(sushi);
   b2.add(TrainedNinja("Hikari", Point(12, 81)));

   while (a1.stillAlive() > 0 && b2.stillAlive() > 0)
   {
      a1.attack(&b2);
      b2.attack(&a1);
      a1.print();
      b2.print();
   }

   if (a1.stillAlive() > 0)
      cout << "winner is a" << endl;
   else
      cout << "winner is b" << endl;

   return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack.
}
