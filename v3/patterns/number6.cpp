#include <iostream>
using namespace std;

/*
Enter n: 5
1
2 1
3 2 1
4 3 2 1
5 4 3 2 1
*/

int main()
{
  int row, col, n;
  cout << "Enter n: ";
  cin >> n;

  row = 1;
  while (row <= n)
  {
    col = 1;
    while (col <= row)
    {
      cout << row - col + 1 << " ";
      col = col + 1;
    }

    cout << endl;
    row = row + 1;
  }

  return 0;
}
