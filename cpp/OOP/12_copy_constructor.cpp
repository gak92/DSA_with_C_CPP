#include <iostream>
using namespace std;

class Number
{
  int num;

public:
  Number() { num = 0; }
  Number(int n)
  {
    num = n;
  }
  // copy constructor
  // When no copy constructor found, compiler supplies its own copy constructor
  Number(Number &obj)
  {
    cout << "Copy constructor called!!!" << endl;
    num = obj.num;
  }
  void Display()
  {
    cout << "The num of object is: " << num << endl;
  }
};

int main()
{
  Number x, y, z(45), z2;

  x.Display();
  y.Display();
  z.Display();

  // Copy constructor invoked
  Number z1(z);
  z1.Display();

  // Copy constructor will not invoked
  z2 = z;
  z2.Display();

  // Copy constructor will Invoked
  Number z3 = z;
  z3.Display();

  return 0;
}