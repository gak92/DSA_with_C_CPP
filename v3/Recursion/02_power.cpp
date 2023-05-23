#include <iostream>
using namespace std;

int power(int n)
{
  // base case
  if (n == 0)
    return 1;

  return 2 * power(n - 1);
}

int main()
{
  int n, res;
  cout << "Enter number to find power of 2: ";
  cin >> n;

  res = power(n);
  cout << "2 Power " << n << " is: " << res << endl;

  return 0;
}