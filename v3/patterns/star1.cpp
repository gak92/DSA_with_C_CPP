#include <iostream>
using namespace std;

/*
Enter n: 5
    *
   **
  ***
 ****
*****
*/

int main()
{
  int row, col, n, space;
  cout << "Enter n: ";
  cin >> n;

  row = 1;
  while (row <= n)
  {
    space = n - row;
    while (space)
    {
      cout << " ";
      space = space - 1;
    }

    col = 1;
    while (col <= row)
    {
      cout << "*";
      col = col + 1;
    }
    cout << endl;
    row = row + 1;
  }

  return 0;
}