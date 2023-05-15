#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int modularExponentiation(int x, int n, int m)
{

  int res = 1;
  while (n > 0)
  {
    if (n & 1)
    {
      res = (1LL * res * (x) % m) % m;
    }

    x = (1LL * (x) % m * (x) % m) % m;
    n = n >> 1;
  }
  return res;
}

int main()
{

  int x = 3, n = 1, m = 2;

  cout << "Result: " << modularExponentiation(x, n, m) << endl;
  cout << "Result: " << modularExponentiation(4, 3, 10) << endl;

  return 0;
}
