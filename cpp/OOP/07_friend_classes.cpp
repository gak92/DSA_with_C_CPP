#include <iostream>
using namespace std;

// Forward Declaration
class Complex;

class Calculator
{
public:
  int add(int a, int b)
  {
    return (a + b);
  }

  int sumRealComplex(Complex o1, Complex o2);
  int sumImagComplex(Complex o1, Complex o2);
};

class Complex
{
  int a, b;

  // Individually declaring functions as friend
  // friend int Calculator ::sumRealComplex(Complex o1, Complex o2);
  // friend int Calculator ::sumImagComplex(Complex o1, Complex o2);

  // Declare whole class as friend
  friend class Calculator;

public:
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

int Calculator ::sumRealComplex(Complex o1, Complex o2)
{
  return (o1.a + o2.a);
}

int Calculator ::sumImagComplex(Complex o1, Complex o2)
{
  return (o1.b + o2.b);
}

int main()
{
  Complex c1, c2;

  c1.setData(1, 3);
  c1.DisplayNumbers();

  c2.setData(5, 7);
  c2.DisplayNumbers();

  Calculator calc;
  int res1 = calc.sumRealComplex(c1, c2);
  cout << "Sum of real part of complex number: " << res1 << endl;

  int res2 = calc.sumImagComplex(c1, c2);
  cout << "Sum of real part of complex number: " << res2 << endl;

  return 0;
}
