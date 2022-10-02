#include <iostream>
using namespace std;

// 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
// 1 5 10 10 5 1

int factorial(int num)
{
  int factorial = 1;

  for (int i = num; i > 1; i--)
  {
    factorial *= i;
  }
  return factorial;
}

int main()
{
  int num = 7;

  for (int i = 0; i < num; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      cout << factorial(i) / (factorial(j) * factorial(i - j)) << "  ";
    }
    cout << endl;
  }

  return 0;
}