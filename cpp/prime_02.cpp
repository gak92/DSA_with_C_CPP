#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int num = 70;
  bool flag = 0;

  for (int i = 2; i <= sqrt(num); i++)
  {
    if (num % i == 0)
    {
      cout << num << " is not a prime number";
      flag = 1;
      break;
    }
  }

  if (flag == 0)
  {
    cout << num << " is a prime number";
  }

  return 0;
}