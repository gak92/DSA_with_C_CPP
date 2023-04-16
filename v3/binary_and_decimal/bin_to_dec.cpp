#include <iostream>
#include <math.h>
using namespace std;

/*
  Enter n: 1110
  Decimal of given number is: 14
*/

int main()
{
  int n, digit, res = 0, i = 0;
  cout << "Enter n: ";
  cin >> n;

  while (n != 0)
  {
    digit = n % 10;

    if (digit == 1)
    {
      res = res + pow(2, i);
    }

    n = n / 10;
    i++;
  }

  cout << "Decimal of given number is: " << res << endl;

  return 0;
}
