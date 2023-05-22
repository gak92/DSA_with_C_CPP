#include <iostream>
using namespace std;

void print(int *p)
{
  cout << "Address: " << p << endl;
  cout << "Value: " << *p << endl;
}

void update(int *p)
{
  // p = p + 1;
  cout << "inside update value of p after update: " << p << endl;
  *p = *p + 1;
}

int getSum(int *arr, int n)
{
  cout << "Size of arr: " << sizeof(arr) << endl;

  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += i[arr];
  }

  return sum;
}

int main()
{
  int value = 5;
  int *p = &value;

  print(p);

  cout << "Before update: " << p << endl;
  cout << "Before update: " << *p << endl;
  update(p);
  cout << "After update: " << p << endl;
  cout << "After update: " << *p << endl;

  cout << endl;
  int arr[5] = {1, 2, 3, 4, 5};
  int res = getSum(arr, 5);
  cout << "Sum is: " << res << endl;

  // pass part of the array
  int res2 = getSum(arr + 3, 2);
  cout << "Sum2 is: " << res2 << endl;

  return 0;
}