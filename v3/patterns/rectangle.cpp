#include <iostream>
using namespace std;
/*
*****
*****
*****
*****
*****
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
      cout << "*";
      j = j + 1;
    }

    cout << endl;
    i = i + 1;
  }

  return 0;
}