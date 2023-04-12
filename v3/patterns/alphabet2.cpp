#include <iostream>
using namespace std;

/*
Enter n: 5
A B C D E
A B C D E
A B C D E
A B C D E
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
    while (col <= n)
    {
      char ch = 'A' + col - 1;
      cout << ch << " ";
      col = col + 1;
    }

    cout << endl;
    row = row + 1;
  }

  return 0;
}
