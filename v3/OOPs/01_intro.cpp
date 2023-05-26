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
  // static allocation
  Hero john;
  john.setHealth(90);
  john.level = 'A';

  cout << "Johne health: " << john.getHealth() << endl;
  cout << "Johne level: " << john.level << endl;

  // dynamically
  Hero *mike = new Hero;
  mike->setHealth(70);
  mike->level = 'B';

  cout << "Mike health: " << mike->getHealth() << endl;
  cout << "Mike level: " << mike->level << endl;

  return 0;
}