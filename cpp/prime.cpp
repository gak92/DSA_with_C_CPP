#include <iostream>
using namespace std;

void isPrime(int n)
{
  int i;

  for (i = 2; i < n; i++)
  {
    if (n % i == 0)
    {
      cout << n << " is not Prime" << endl;
      break;
    }
  }
  if (i == n)
  {
    cout << n << " is a Prime Number" << endl;
  }
}

void printAllPrime(int a, int b)
{

  for (int num = a; num <= b; num++)
  {
    int i;
    for (i = 2; i < num; i++)
    {
      if (num % i == 0)
      {
        cout << num << " is not Prime" << endl;
        break;
      }
    }
    if (i == num)
    {
      cout << num << " is Prime" << endl;
    }
  }
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  // cout << "Enter a number: " << endl;
  cin >> n;
  isPrime(n);

  int a, b;
  cin >> a >> b;
  printAllPrime(a, b);

  return 0;
}