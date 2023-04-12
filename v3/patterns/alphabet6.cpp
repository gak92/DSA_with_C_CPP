#include <iostream>
using namespace std;

/*
Enter n: 5
A
B C
D E F
G H I J
K L M N O
*/

int main()
{
  int row, col, n, start = 0;
  cout << "Enter n: ";
  cin >> n;

  row = 1;
  while (row <= n)
  {
    col = 1;
    while (col <= row)
    {
      char ch = 'A' + start;
      cout << ch << " ";
      col = col + 1;
      start = start + 1;
    }

    cout << endl;
    row = row + 1;
  }

  return 0;
}
