#include <iostream>
using namespace std;

int main()
{
  int a = 5;
  int &b = a;
  int *c = &a;

  // & ---> (Address of) operator
  cout << "value of a: " << a << endl;
  cout << "value of b: " << b << endl;

  cout << "Address of a: " << &a << endl;
  cout << "Address of b: " << &b << endl;

  // * ---> (Value at) Dereference operator
  cout << "value of c: " << c << endl;
  cout << "Address of c: " << &c << endl;
  cout << "Value at the address store in c: " << *c << endl;

  // Pointer to pointer
  int **d = &c;
  cout << "Address of c: " << &c << endl;
  cout << "Address of c: " << d << endl;

  cout << "Value at address d: " << *d << endl;
  cout << "Value at value at address of d: " << **d << endl;

  return 0;
}