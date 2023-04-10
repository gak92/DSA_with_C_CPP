#include <iostream>
using namespace std;

/*
12345
12345
12345
12345
12345

Reverse Order:
54321
54321
54321
54321
54321
*/

int main()
{
  int i, j, n;
  cout << "Enter n: ";
  cin >> n;

  i = 1;
  while (i <= n)
  {
    j = 1;
    while (j <= n)
    {
      cout << j;
      j = j + 1;
    }

    cout << endl;
    i = i + 1;
  }

  // Print in reverse order
  cout << "\nReverse Order: " << endl;
  i = 1;
  while (i <= n)
  {
    j = 1;
    while (j <= n)
    {
      cout << n - j + 1;
      j = j + 1;
    }

    cout << endl;
    i = i + 1;
  }

  return 0;
}
