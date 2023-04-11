#include <iostream>
using namespace std;

/*
Enter n: 5
1
22
333
4444
55555
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
      cout << row;
      col = col + 1;
    }

    cout << endl;
    row = row + 1;
  }

  return 0;
}
