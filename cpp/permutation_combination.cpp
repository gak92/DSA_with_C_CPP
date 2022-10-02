#include <iostream>
using namespace std;

int factorial(int num)
{
  int factorial = 1;

  for (int i = num; i > 1; i--)
  {
    factorial *= i;
  }
  return factorial;
}

int main()
{
  int n = 6;
  int r = 3;
  int permutation, combination;

  cout << "\nFactorial of " << n << " is: " << factorial(n);

  permutation = factorial(n) / (factorial(n - r));
  cout << "\nPermutaion of " << n << "P" << r << " is: " << permutation;

  combination = factorial(n) / (factorial(r) * factorial(n - r));
  cout << "\nCombination of " << n << "C" << r << " is: " << combination;

  return 0;
}