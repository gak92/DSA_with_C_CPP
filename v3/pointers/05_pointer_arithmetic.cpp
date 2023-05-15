#include <iostream>
using namespace std;

int main()
{
  int num = 5;

  cout << "Value of num: " << num << endl;
  cout << "Address of num: " << &num << endl;

  int *p = &num;
  // cout << "Increment value: " << (*p)++ << endl;
  *p = *p + 1;
  cout << "Increment value: " << *p << endl;

  p = p + 1;
  cout << "Increment address: " << p << endl;

  return 0;
}