#include <iostream>
using namespace std;

/*
Enter n: 5
1
2 3
3 4 5
4 5 6 7
5 6 7 8 9

Second method:
1
2 3
3 4 5
4 5 6 7
5 6 7 8 9
*/

int main()
{
  int row, col, n, count;
  cout << "Enter n: ";
  cin >> n;

  row = 1;
  while (row <= n)
  {
    col = 1;
    count = row;
    while (col <= row)
    {
      cout << count << " ";
      count = count + 1;
      col = col + 1;
    }

    cout << endl;
    row = row + 1;
  }

  // Second method
  cout << "Second method: " << endl;
  row = 1;
  while (row <= n)
  {
    col = 1;
    while (col <= row)
    {
      cout << row + col - 1 << " ";
      col = col + 1;
    }

    cout << endl;
    row = row + 1;
  }

  return 0;
}
