#include <iostream>
#include <math.h>
using namespace std;

/*
  Enter n: 15
  Binary of given number is: 1111
*/

int main()
{
  int n, bit, res = 0, i = 0;
  cout << "Enter n: ";
  cin >> n;

  while (n != 0)
  {
    bit = n & 1;
    res = (bit * pow(10, i)) + res;
    n = n >> 1;
    i++;
  }

  cout << "Binary of given number is: " << res << endl;

  return 0;
}

/*
  Number:   123

  Same Flow:
    ans = 0
    ans = (ans * 10) + digit

    ans = (0 * 10) + 1 = 1
    ans = (1 * 10) + 2 = 12
    ans = (12 * 10) + 3 = 123


  Reverse Flow:
    ans = 0, i = 0
    ans = (digit * pow(10,i)) + ans

    ans = (1 * pow(10, 0)) + 0 = 1
    i++ = 1

    ans = (2 * pow(10, 1)) + 1 = 21
    i++ = 2

    ams = (3 * pow(10, 2)) + 21 = 321


*/