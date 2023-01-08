#include<iostream>
#include<math.h>
using namespace std;

bool isPrime(int num)
{
  for(int i=2; i<=sqrt(num); i++)
  {
    if(num%i == 0)
      return false;
  }
  return true;
}

int main()
{
  int a, b;
  cout << "Enter two number to find prime in between: ";
  cin >> a >> b;

  cout << endl << "Prime numbers between "<< a << " and " << b << ": ";
  for(int i=a; i<=b; i++)
  {
    if(isPrime(i))
    {
      cout << i << " ";
    }
  }
  cout << endl;
  return 0;
}