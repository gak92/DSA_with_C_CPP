#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
  1- Shallow Copy - Default Constructor
  2- Deep Copy - We have to write our own constructor
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
};

int main()
{
  // Shallow Copy and Deep Copy
  Hero h3;
  h3.setHealth(12);
  h3.level = 'E';
  char name[3] = "h3";
  h3.setName(name);
  h3.print();

  // use default copy constructor
  Hero h4(h3);
  // Hero h4 = h3;
  h4.print();

  // Due to shallow copy (Use Default Constructor) - access same memory and changes will see on both print
  // Due to Deep copy (Use our constructor) - now the address is different and changes will only h3
  h3.name[0] = 'Y';
  h3.print();
  h4.print();

  // Copy using Deep copy
  // Hero h5 = h3;
  // h5.print();

  return 0;
}