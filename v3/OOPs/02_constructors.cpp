#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
  1- Default Constructor
  2- Parametrized Constructor
  3- Copy Constructor
*/

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
    this->health = h.health;
    this->level = h.level;
  }

  void print()
  {
    cout << "level: " << this->level << ", ";
    cout << "health: " << this->health << endl;
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
};

int main()
{
  // static allocation
  cout << "Befor constructor called" << endl;
  Hero john(70);
  cout << "Address of john: " << &john << endl;
  cout << "After constructor called" << endl;

  cout << endl;

  // dynamically
  cout << "Befor constructor called" << endl;
  Hero *mike = new Hero(90);
  cout << "Address of mike: " << mike << endl;
  cout << "After constructor called" << endl;

  cout << endl;

  // calling copy constructor
  Hero h1(40, 'C');
  h1.print();

  Hero h2(h1);
  h2.print();

  return 0;
}