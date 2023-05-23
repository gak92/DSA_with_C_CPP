#include <iostream>
using namespace std;

// DONT DO THIS
// BAD PRACTICE - Return reference variable as
// Referece to stack memory associated with local variable
int &func(int a)
{
  int num = a;
  int &res = num;
  return res;
}

// same is true for returning pointers variable
int *func2(int n)
{
  int *ptr = &n;
  return ptr;
}

void passByValue(int n)
{
  n++;
}

void passByReference(int &n)
{
  n++;
}

int main()
{

  int n = 5;

  cout << "Before Changes: " << n << endl;

  passByValue(n);
  cout << "After pass by value and changes: " << n << endl;

  passByReference(n);
  cout << "After pass by Reference and changes: " << n << endl;

  int res = func(11);
  cout << "Res: " << res << endl;

  return 0;
}