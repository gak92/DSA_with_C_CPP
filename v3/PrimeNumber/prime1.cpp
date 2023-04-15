#include <iostream>
using namespace std;

int main()
{
  int n, i;
  cout << "Enter n: ";
  cin >> n;
  bool isPrime = 1;

  for (i = 2; i < n; i++)
  {
    if (n % i == 0)
    {
      isPrime = 0;
      break;
    }
  }

  if (isPrime)
  {
    cout << n << " is a Prime Number" << endl;
  }
  else
  {
    cout << n << " is not a Prime Number" << endl;
    cout << n << " is divisible by " << i << endl;
  }

  return 0;
}