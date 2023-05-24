#include <iostream>
using namespace std;

void printArray(int *arr, int size)
{
  cout << "size of array: " << size << endl;

  cout << "Array element: ";
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int linearSearch(int *arr, int size, int key)
{
  printArray(arr, size);
  if (size == 0)
    return false;

  if (arr[0] == key)
    return true;
  else
    return linearSearch(arr + 1, size - 1, key);
}

int main()
{
  int arr[5] = {3, 5, 1, 2, 6};
  int size = 5;
  int key = 2;

  int res = linearSearch(arr, size, key);

  if (res)
    cout << "Key found" << endl;
  else
    cout << "Key not found" << endl;

  return 0;
}