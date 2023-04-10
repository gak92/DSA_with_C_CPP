#include <iostream>
using namespace std;

/*
Enter n: 5
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25
*/

int main()
{
  int i, j, n, count = 1;
  cout << "Enter n: ";
  cin >> n;

  i = 1;
  while (i <= n)
  {
    j = 1;
    while (j <= n)
    {
      cout << count << " ";
      count = count + 1;
      j = j + 1;
    }

    cout << endl;
    i = i + 1;
  }

  return 0;
}
