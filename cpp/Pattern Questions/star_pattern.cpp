#include <iostream>
using namespace std;

int main()
{
  int num = 5;

  for (int i = 1; i <= num; i++)
  {
    for (int k = 1; k <= num - i; k++)
    {
      cout << " ";
    }
    for (int j = 1; j <= 2 * i - 1; j++)
    {
      cout << "*";
    }
    cout << endl;
  }

  for (int i = num; i >= 1; i--)
  {
    for (int k = 1; k <= num - i; k++)
    {
      cout << " ";
    }
    for (int j = 1; j <= 2 * i - 1; j++)
    {
      cout << "*";
    }
    cout << endl;
  }
  return 0;
}