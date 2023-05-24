#include <iostream>
using namespace std;

void printArray(int *arr, int start, int end)
{
  cout << "Array element: ";
  for (int i = start; i <= end; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

bool binarySearch(int *arr, int start, int end, int key)
{
  printArray(arr, start, end);
  if (start > end)
    return false;

  int mid = start + (end - start) / 2;
  cout << "mid: " << arr[mid] << endl;

  if (arr[mid] == key)
    return true;
  else if (arr[mid] < key)
    return binarySearch(arr, mid + 1, end, key);
  else
    return binarySearch(arr, start, mid - 1, key);
}

int main()
{
  int arr[7] = {7, 11, 19, 21, 27, 40, 41};
  int size = 7;
  int key = 41;

  int start = 0;
  int end = size - 1;

  cout << "Key: " << key << endl
       << endl;
  int res = binarySearch(arr, start, end, key);

  if (res)
    cout << "Element found" << endl;
  else
    cout << "Element not found" << endl;

  return 0;
}