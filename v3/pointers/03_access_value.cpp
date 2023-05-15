#include <iostream>
using namespace std;

int main()
{
  int num = 5;

  cout << "Value of num: " << num << endl;
  cout << "Address of num: " << &num << endl;

  int *ptr = &num;
  cout << "Before increment: " << num << endl;
  (*ptr)++;
  cout << "After increment: " << num << endl;

  return 0;
}