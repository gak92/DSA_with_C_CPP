#include <iostream>
using namespace std;

class Complex
{
  int a, b;

public:
  void setData(int v1, int v2)
  {
    a = v1;
    b = v2;
  }

  void SetDataBySum(Complex o1, Complex o2)
  {
    a = o1.a + o2.a;
    b = o1.b + o2.b;
  }

  void DisplayNumbers(void)
  {
    cout << a << "+" << b << "i" << endl;
  }
};

int main()
{
  Complex c1, c2, c3;

  c1.setData(1, 3);
  c1.DisplayNumbers();

  c2.setData(2, 4);
  c2.DisplayNumbers();

  c3.SetDataBySum(c1, c2);
  c3.DisplayNumbers();

  return 0;
}