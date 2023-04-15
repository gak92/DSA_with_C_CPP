#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter n: ";
  cin >> n;
  int a = 0;
  int b = 1;

  cout << a << " " << b;
  for (int i = 1; i <= n; i++)
  {
    int nextNum = a + b;
    cout << " " << nextNum;

    a = b;
    b = nextNum;
  }
  return 0;
}