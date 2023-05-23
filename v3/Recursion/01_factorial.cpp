#include <iostream>
using namespace std;

int factorial(int n)
{
  // base case
  if (n == 0)
    return 1;

  return n * factorial(n - 1);
}

int main()
{
  int n, res;
  cout << "Enter number to find factorial: ";
  cin >> n;

  res = factorial(n);
  cout << "Factorial of " << n << " is: " << res << endl;

  return 0;
}