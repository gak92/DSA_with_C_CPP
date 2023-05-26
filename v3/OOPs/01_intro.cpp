#include <iostream>
using namespace std;

class Hero
{
private:
  int health;

public:
  char level;

  void print()
  {
    cout << "level: " << level << endl;
  }

  void setHealth(int h)
  {
    health = h;
  }

  int getHealth()
  {
    return health;
  }
};

int main()
{
  Hero john;
  john.setHealth(90);
  john.level = 'A';

  cout << "Johne health: " << john.getHealth() << endl;
  cout << "Johne level: " << john.level << endl;

  return 0;
}