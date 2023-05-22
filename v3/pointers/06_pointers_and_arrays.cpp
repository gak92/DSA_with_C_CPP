#include <iostream>
using namespace std;

int main()
{
  // Basics of pointers with arrays
  int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  cout << "Address of the first block of array: " << arr << endl;
  cout << "Address of the first block of array: " << &arr[0] << endl;

  cout << "Value at 1st block of array: " << arr[0] << endl;
  cout << "Value at 1st block of array: " << *arr << endl;

  cout << "Increment value at 1st block: " << *arr + 1 << endl;
  cout << "Value at 2nd block of array: " << *(arr + 1) << endl;

  cout << "3rd block of array: " << 2 [arr] << endl;
  cout << "3rd block of array: " << *(2 + arr) << endl;

  // Difference between Pointers and Arrays
  // Pointer variable store address thats why need 8 bytes
  int temp[10] = {11, 12, 13, 14, 15};

  cout << "\nSize of temp: " << sizeof(temp) << endl;
  cout << "Size of *temp: " << sizeof(*temp) << endl;
  cout << "Size of &temp: " << sizeof(&temp) << endl;

  int *ptr = &temp[0];
  cout << "Size of ptr: " << sizeof(ptr) << " (" << ptr << ")" << endl;
  cout << "Size of *ptr: " << sizeof(*ptr) << " (" << *ptr << ")" << endl;
  cout << "Size of &ptr: " << sizeof(&ptr) << " (" << &ptr << ")" << endl;

  // address of array and address of pointer variable
  int a[5] = {21, 22, 23, 24, 25};
  cout << "\nAddress of a: " << a << endl;
  cout << "Address of a: " << &a << endl;
  cout << "Address of a: " << &a[0] << endl;

  int *p = &a[0];
  cout << "Value at pointer variable p: " << p << endl;
  cout << "Address of pointer variable p: " << &p << endl;
  cout << "Value point by address at pointer variable p: " << *p << endl;

  // 3rd difference: Symbol table cannot change
  int brr[5] = {19, 21, 27, 41, 92};

  // Error
  // brr = brr + 1;

  int *q = brr;
  cout << "\n--------> " << q << endl;
  q = q + 1;
  cout << "--------> " << q << endl;

  return 0;
}