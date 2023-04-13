#include <iostream>
using namespace std;

/*
Enter n: 5
    1
   23
  456
 78910
1112131415
*/

int main()
{
  int row, col, n, space, count = 1;
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
      cout << count;
      col = col + 1;
      count = count + 1;
    }
    cout << endl;
    row = row + 1;
  }

  return 0;
}