#include <iostream>
using namespace std;

bool isEven(int n)
{
  // odd
  if (n & 1)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

int main()
{
  int n;
  cout << "Enter number: ";
  cin >> n;

  if (isEven(n))
  {
    cout << n << " is even number" << endl;
  }
  else
  {
    cout << n << " is odd number" << endl;
  }

  return 0;
}