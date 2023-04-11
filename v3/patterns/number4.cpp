#include <iostream>
using namespace std;

/*
Enter n: 5
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
*/

int main()
{
  int row, col, n, count = 1;
  cout << "Enter n: ";
  cin >> n;

  row = 1;
  while (row <= n)
  {
    col = 1;
    while (col <= row)
    {
      cout << count << " ";
      count = count + 1;
      col = col + 1;
    }

    cout << endl;
    row = row + 1;
  }

  return 0;
}
