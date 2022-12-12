#include <iostream>
using namespace std;

class Base1
{
public:
  void greet()
  {
    cout << "Hello" << endl;
  }
};

class Base2
{
public:
  void greet()
  {
    cout << "Kese ho?" << endl;
  }
};

class Derived : public Base1, public Base2
{
  int a;

public:
  void greet()
  {
    Base1::greet();
  }
};

class B
{
public:
  void say()
  {
    cout << "Hello World" << endl;
  }
};

class D : public B
{
public:
  void say()
  {
    cout << "Hello CPP" << endl;
  }
};

int main()
{
  Base1 b1;
  b1.greet();

  Base2 b2;
  b2.greet();

  Derived d;
  d.greet();

  B b;
  b.say();

  D e;
  e.say();

  return 0;
}