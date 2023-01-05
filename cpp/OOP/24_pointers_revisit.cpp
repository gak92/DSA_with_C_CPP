#include <iostream>
using namespace std;

int main()
{
  int a = 4;
  int *ptr = &a;

  cout << "Value of a: " << a << endl;
  cout << "Address of a: " << ptr << endl;
  cout << "Acces value of a using pointer: " << *ptr << endl;

  // NEW Keyword
  float *p = new float(40.41);
  cout << "value of p: " << *p << endl;

  int *arr = new int[3];
  arr[0] = 10;
  // arr[1] = 20;
  *(arr+1) = 20;
  arr[2] = 30;

  cout << "Value of arr[0]: " << arr[0] << endl;
  cout << "Value of arr[1]: " << arr[1] << endl;
  cout << "Value of arr[2]: " << arr[2] << endl;

  // To remove an entire array and free up memory
  delete[] arr;
  cout << "After deletion: " << endl; 
  cout << "Value of arr[0]: " << arr[0] << endl;
  cout << "Value of arr[1]: " << arr[1] << endl;
  cout << "Value of arr[2]: " << arr[2] << endl;
  

  return 0;
}