/*
7. Reverse Integer

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).


Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
*/
#include <iostream>
#include <climits>
using namespace std;

int main()
{
  int x;
  cout << "Enter x: ";
  cin >> x;

  int res = 0;

  while (x != 0)
  {
    int digit = x % 10;

    if ((res > INT_MAX / 10) || (res < INT_MIN / 10))
    {
      return 0;
    }

    res = (res * 10) + digit;

    x = x / 10;
  }

  cout << "Reverse Number is: " << res << endl;

  return 0;
}