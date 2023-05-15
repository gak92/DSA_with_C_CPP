#include <iostream>
using namespace std;

int main()
{
  int num = 5;

  cout << "Value of num: " << num << endl;
  cout << "Address of num: " << &num << endl;

  int *ptr = &num;
  int *q = ptr;

  cout << ptr << " ---- " << q << endl;
  cout << *ptr << " --- " << *q << endl;

  return 0;
}