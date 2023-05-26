#include <iostream>
using namespace std;

class Hero
{
public:
  int health;
  char level;

  void print()
  {
    cout << "level: " << level << endl;
  }
};

int main()
{
  Hero john;
  john.health = 90;
  john.level = 'A';

  cout << "Johne health: " << john.health << endl;
  cout << "Johne level: " << john.level << endl;

  return 0;
}