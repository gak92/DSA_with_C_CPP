#include <iostream>
using namespace std;

class Complex
{
  int a, b;

public:
  // Default Constructor
  Complex(void)
  {
    a = 0;
    b = 0;
  }

  // Parametrized Constructor
  Complex(int x, int y)
  {
    a = x;
    b = y;
  }

  void displayData(void)
  {
    cout << "Your data is: " << a << " + " << b << "i" << endl;
  }
};

int main()
{
  Complex c1;
  c1.displayData();

  // Implicit call
  Complex c2(4, 6);
  c2.displayData();

  // Explicit call
  Complex c3 = Complex(5, 7);
  c3.displayData();

  return 0;
}

/*

Characteristics of Constructors
1- Should declare in public section of class
2- Automatically invoked when object is created
3- They don't return value and neither have return types
4- It can have default arguments
5- We cannot refer to their address

*/