#include <iostream>
using namespace std;

/*
Enter n: 5
A
B B
C C C
D D D D
E E E E E
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
    char ch = 'A' + row - 1;
    while (col <= row)
    {
      cout << ch << " ";
      col = col + 1;
    }

    cout << endl;
    row = row + 1;
  }

  return 0;
}
