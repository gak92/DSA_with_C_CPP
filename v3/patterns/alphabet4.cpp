#include <iostream>
using namespace std;

/*
Enter n: 5
A B C D E
B C D E F
C D E F G
D E F G H
E F G H I
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
      char ch = 'A' + row + col - 2;
      cout << ch << " ";
      col = col + 1;
    }

    cout << endl;
    row = row + 1;
  }

  return 0;
}
