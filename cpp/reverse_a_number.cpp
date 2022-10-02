#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int num = 1234;
  int reverse = 0;

  while (num > 0)
  {
    int lastDigit = num % 10;
    reverse = (reverse * 10) + lastDigit;
    num = num / 10;
  }

  cout << "Given number is: " << num;
  cout << "Reverse number is: " << reverse;

  return 0;
}