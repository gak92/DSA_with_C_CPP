#include <iostream>
using namespace std;

/*
Enter n: 5
11111
 2222
  333
   44
    5
*/

int main()
{
  int row, col, n, space;
  cout << "Enter n: ";
  cin >> n;

  row = 1;
  while (row <= n)
  {
    space = row - 1;
    while (space)
    {
      cout << " ";
      space = space - 1;
    }

    col = 1;
    while (col <= n - row + 1)
    {
      cout << row;
      col = col + 1;
    }
    cout << endl;
    row = row + 1;
  }

  return 0;
}