#include <iostream>
using namespace std;

int main()
{
  int num = 5;

  cout << "Value of num: " << num << endl;
  cout << "Address of num: " << &num << endl;

  int *ptr = &num;

  cout << "Address is: " << ptr << endl;
  cout << "Value is: " << *ptr << endl;

  // never initialize pointer without value (it return garbage)
  // int *q;
  // cout << "q pointer point at: " << q << endl;

  int *r = 0;
  r = &num;
  cout << "r store address: " << r << endl;
  cout << "r point to value: " << *r << endl;

  return 0;
}