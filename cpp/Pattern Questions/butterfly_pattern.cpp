#include <iostream>
using namespace std;

// *        *
// **      **
// ***    ***
// ****  ****
// **********
// **********
// ****  ****
// ***    ***
// **      **
// *        *

int main()
{
  int num = 5;
  int spaces;

  for (int i = 1; i <= num; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << "*";
    }
    spaces = 2 * num - 2 * i;

    for (int j = 1; j <= spaces; j++)
    {
      cout << " ";
    }
    for (int j = 1; j <= i; j++)
    {
      cout << "*";
    }
    cout << endl;
  }

  for (int i = num; i >= 1; i--)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << "*";
    }
    spaces = 2 * num - 2 * i;

    for (int j = 1; j <= spaces; j++)
    {
      cout << " ";
    }
    for (int j = 1; j <= i; j++)
    {
      cout << "*";
    }
    cout << endl;
  }

  return 0;
}