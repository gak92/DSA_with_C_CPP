#include <iostream>
using namespace std;

int getSum(int *arr, int n)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
  }
  return sum;
}

int main()
{
  char ch = 'a';
  cout << sizeof(ch) << endl;

  char *c = &ch;
  cout << sizeof(c) << endl;

  // variable size array using Heap (Dynamic memory allocation)
  int n;
  cout << "Enter the size of the array: ";
  cin >> n;
  int *arr = new int[n];

  cout << "Enter array elements using space: ";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int res = getSum(arr, n);
  cout << "Sum is: " << res << endl;

  return 0;
}