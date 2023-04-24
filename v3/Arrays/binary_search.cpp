#include <iostream>
using namespace std;

int binary_search(int arr[], int size, int key)
{
  int start = 0, end = size - 1;
  // int mid = (start + end) / 2;
  // OR
  int mid = start + (end - start) / 2;

  while (start <= end)
  {
    if (key == arr[mid])
    {
      return mid;
    }
    if (key > arr[mid])
    {
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
    // mid = (start + end) / 2;
    // OR
    mid = start + (end - start) / 2;
  }

  return -1;
}

int main()
{
  int even[6] = {2, 4, 6, 8, 10, 12};
  int key1 = 1;
  int evenIndex = binary_search(even, 6, key1);
  cout << "Index of " << key1 << " :" << evenIndex << endl;

  int odd[5] = {3, 5, 7, 11, 19};
  int key2 = 3;
  int oddIndex = binary_search(odd, 5, key2);
  cout << "Index of " << key2 << " :" << oddIndex << endl;

  return 0;
}