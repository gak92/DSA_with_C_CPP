#include <iostream>
using namespace std;

int factorial(int n)
{
  int fact = 1;
  for (int i = 2; i <= n; i++)
  {
    fact = fact * i;
  }
  return fact;
}

int nCr(int n, int r)
{
  int numerator, denominator;

  numerator = factorial(n);
  denominator = factorial(r) * factorial(n - r);

  return numerator / denominator;
}

int main()
{
  int n, r;
  cout << "Enter n and r: ";
  cin >> n >> r;

  cout << n << "C" << r << " is: " << nCr(n, r) << endl;

  return 0;
}