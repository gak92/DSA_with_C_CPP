#include <iostream>
using namespace std;
/*
11111
22222
33333
44444
55555
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
      cout << i;
      j = j + 1;
    }

    cout << endl;
    i = i + 1;
  }

  return 0;
}
