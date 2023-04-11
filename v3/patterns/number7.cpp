#include <iostream>
using namespace std;

/*
Enter n: 5
A A A A A
B B B B B
C C C C C
D D D D D
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
    while (col <= n)
    {
      char ch = 'A' + row - 1;
      cout << ch << " ";
      col = col + 1;
    }

    cout << endl;
    row = row + 1;
  }

  return 0;
}
