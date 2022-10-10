#include <iostream>
using namespace std;

class Complex
{
  int a, b;

public:
  friend Complex ComplexSum(Complex o1, Complex o2);
  void setData(int v1, int v2)
  {
    a = v1;
    b = v2;
  }

  void DisplayNumbers(void)
  {
    cout << a << "+" << b << "i" << endl;
  }
};

Complex ComplexSum(Complex o1, Complex o2)
{
  Complex o3;
  o3.setData((o1.a + o2.a), (o1.b + o2.b));
  return o3;
}

int main()
{
  Complex c1, c2, c3;

  c1.setData(1, 3);
  c1.DisplayNumbers();

  c2.setData(5, 7);
  c2.DisplayNumbers();

  c3 = ComplexSum(c1, c2);
  c3.DisplayNumbers();

  return 0;
}

/*
Properties of friend function:
1- not the part of class
2- cannot called from the object
3- Usually contains objects as arguments
4- Can be declared in public or private section in the class
5- It cannot access class members directly. It can access through object only.

*/