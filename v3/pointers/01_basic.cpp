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

  cout << "Size of num: " << sizeof(num) << endl;
  cout << "Size of pointer: " << sizeof(ptr) << endl;

  return 0;
}