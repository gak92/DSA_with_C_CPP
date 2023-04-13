#include <iostream>
using namespace std;

/*
Enter n: 5
E
D E
C D E
B C D E
A B C D E
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
    char ch = 'A' + n - row;
    while (col <= row)
    {
      cout << ch << " ";
      col = col + 1;
      ch = ch + 1;
    }

    cout << endl;
    row = row + 1;
  }

  return 0;
}
