#include <iostream>
using namespace std;

int main()
{

  int num = 5;
  // cin >> num;

  // Inverted Half Pyramid
  for (int i = 0; i < num; i++)
  {
    for (int j = num - i; j > 0; j--)
    {
      cout << "*";
    }
    cout << "\n";
  }

  // Half Pyramid after 180 degree rotation
  for (int i = 1; i <= num; i++)
  {
    for (int j = 1; j <= num; j++)
    {
      if (j <= num - i)
      {
        cout << " ";
      }
      else
      {
        cout << "*";
      }
    }
    cout << endl;
  }

  // Half pyramid using numbers
  for (int i = 1; i <= num; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << i;
    }
    cout << endl;
  }

  return 0;
}
