#include <iostream>
using namespace std;

int power(int a, int b)
{
  if (b == 0)
    return 1;

  if (b == 1)
    return a;

  int res = power(a, b / 2);

  if (b % 2 == 0)
    return res * res;
  else
    return a * res * res;
}

int main()
{

  int a, b;
  cout << "Enter a and b: ";
  cin >> a >> b;

  int res = power(a, b);
  cout << a << " Power" << b << " is: " << res << endl;

  return 0;
}