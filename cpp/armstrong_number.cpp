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
  int original = num;
  int armstrong = 0;

  while (num > 0)
  {
    int lastDigit = num % 10;
    armstrong += pow(lastDigit, 3);
    num = num / 10;
  }

  cout << "Given number is: " << original << endl;

  if(original == armstrong)
  {
    cout << "Armstrong number is: " << armstrong << endl;
    cout << original << " is armstrong number" << endl;
  }
  else
    cout << original << " is not armstrong number" << endl;

  return 0;
}