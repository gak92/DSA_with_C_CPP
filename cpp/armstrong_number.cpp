#include <iostream>
#include <math.h>
using namespace std;

int cube(int num)
{
  return num * num * num;
}

int main()
{
  int num = 153;
  int armstrong = 0;

  cout << "Given number is: " << num << endl;
  while (num > 0)
  {
    int lastDigit = num % 10;
    armstrong += pow(lastDigit, 3);
    num = num / 10;
  }

  cout << "Armstrong number is: " << armstrong;

  return 0;
}