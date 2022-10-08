#include <iostream>
using namespace std;

// Swap by passing values
void swapByValue(int a, int b)
{
  int temp = a;
  a = b;
  b = temp;
}

// Swap by passing references
void swapByReference(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Swap by passing c++ reference variable
void swapByReferenceVariable(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

int main()
{
  int x = 4, y = 8;

  cout << "Before Swapping:" << endl;
  cout << "Value of x is: " << x << endl;
  cout << "Value of y is: " << y << endl;

  swapByValue(x, y);
  cout << "After Swapping By Value:" << endl;
  cout << "Value of x is: " << x << endl;
  cout << "Value of y is: " << y << endl;

  swapByReference(&x, &y);
  cout << "After Swapping By Reference:" << endl;
  cout << "Value of x is: " << x << endl;
  cout << "Value of y is: " << y << endl;

  swapByReferenceVariable(x, y);
  cout << "After Swapping By Reference:" << endl;
  cout << "Value of x is: " << x << endl;
  cout << "Value of y is: " << y << endl;

  return 0;
}