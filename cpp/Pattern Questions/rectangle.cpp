#include <iostream>
using namespace std;

int main()
{
  // #ifndef ONLINE_JUDGE
  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", stdout);
  // #endif

  int row = 4, col = 4;
  // cin >> row >> col;

  // Rectangle Pattern
  cout << "Rectangle:" << endl;
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      cout << "*";
    }
    cout << endl;
  }

  // Hollow Rectangle pattern
  cout << "Hollow Rectangle:" << endl;
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      if (i == 0 || j == 0 || i == row - 1 || j == col - 1)
      {
        cout << "*";
      }
      else
      {
        cout << " ";
      }
    }
    cout << endl;
  }

  return 0;
}
