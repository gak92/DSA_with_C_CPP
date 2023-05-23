#include <iostream>
using namespace std;

void printCountingDescending(int n)
{
  // base case
  if (n == 0)
    return;

  cout << n << " ";
  printCountingDescending(n - 1);
}

void printCountingAscending(int n)
{
  // base case
  if (n == 0)
    return;

  printCountingAscending(n - 1);
  cout << n << " ";
}

int main()
{
  int n;
  cout << "Enter number to print counting: ";
  cin >> n;

  cout << "Desceding: ";
  printCountingDescending(n);
  cout << endl;

  cout << "Ascending: ";
  printCountingAscending(n);
  cout << endl;

  return 0;
}