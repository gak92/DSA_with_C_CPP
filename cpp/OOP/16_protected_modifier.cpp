#include <iostream>
using namespace std;

class Base
{
protected:
  int a;

private:
  int b;
};
/*
For protected member:
                      Public Derivation     Private Derivation    Protected Derivation
Private members:        Not inherit           Not inherit           Not inherit
Protected member:       Protected             Private               Protected
Public members:         Public                Private               Protected
*/
class Derived : protected Base
{
};

int main()
{
  Base b;
  Derived d;

  // This will not work because a is protected in both Base and Derived class.
  // cout << d.a;

  return 0;
}