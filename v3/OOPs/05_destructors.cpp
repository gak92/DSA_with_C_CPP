#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Hero
{
private:
  int health;

public:
  char level;
  char *name;

  // default constructor
  Hero()
  {
    cout << "constructor called" << endl;
    name = new char[100];
  }

  // parametrized constructor
  Hero(int health)
  {
    cout << "Address of this: " << this << endl;
    this->health = health;
  }

  Hero(int health, char level)
  {
    this->health = health;
    this->level = level;
  }

  // copy constructor
  Hero(Hero &h)
  {
    cout << "Copy constructor called... " << endl;

    char *ch = new char[strlen(h.name) + 1]; // create an new character array
    strcpy(ch, h.name);                      // copy name into new array
    this->name = ch;                         // store the new array address

    this->health = h.health;
    this->level = h.level;
  }

  void print()
  {
    cout << "[ name: " << this->name << ", ";
    cout << "level: " << this->level << ", ";
    cout << "health: " << this->health << " ]" << endl;
  }

  void setHealth(int h)
  {
    health = h;
  }

  int getHealth()
  {
    return health;
  }

  void setName(char name[])
  {
    strcpy(this->name, name);
  }

  ~Hero()
  {
    cout << "Destructor called... " << endl;
  }
};

int main()
{
  // static - Desctructor called automatically
  Hero a;

  // dynamic - we have to called manually
  Hero *b = new Hero();
  delete b;

  return 0;
}