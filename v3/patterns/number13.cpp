#include <iostream>
using namespace std;

/*
Enter n: 8
1234567887654321
1234567**7654321
123456****654321
12345******54321
1234********4321
123**********321
12************21
1**************1
*/

int main()
{
  int row, col, n, star;
  cout << "Enter n: ";
  cin >> n;

  row = 1;
  while (row <= n)
  {
    col = 1;
    while (col <= n - row + 1)
    {
      cout << col;
      col = col + 1;
    }

    star = 1;
    while (star <= row - 1)
    {
      cout << "*";
      star = star + 1;
    }

    star = 1;
    while (star <= row - 1)
    {
      cout << "*";
      star = star + 1;
    }

    col = 1;
    while (col <= n - row + 1)
    {
      cout << n - col - row + 2;
      col = col + 1;
    }

    cout << endl;
    row = row + 1;
  }

  return 0;
}