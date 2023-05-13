#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
  if (a == 0)
    return b;

  if (b == 0)
    return a;

  while (a != b)
  {
    if (a > b)
    {
      a = a - b;
    }
    else
    {
      b = b - a;
    }
    cout << a << " " << b << endl;
  }
  return a;
}

int main()
{
  int a = 24;
  int b = 72;

  cout << "GCD of " << a << " and " << b << ": " << gcd(a, b) << endl;

  return 0;
}
