#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getPivotIndex(vector<int> arr)
{
  int start = 0;
  int end = arr.size() - 1;
  int mid = start + (end - start) / 2;

  while (start < end)
  {
    if (arr[mid] >= arr[0])
    {
      start = mid + 1;
    }
    else
    {
      end = mid;
    }
    mid = start + (end - start) / 2;
  }
  return start;
}

int binarySearch(vector<int> arr, int start, int end, int key)
{
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
    mid = start + (end - start) / 2;
  }
  return -1;
}

int main()
{
  vector<int> arr = {12, 15, 18, 2, 4};
  int n = arr.size() - 1;
  int k = 18;

  int pivotIndex = getPivotIndex(arr);
  cout << "Pivot is at index: " << pivotIndex << endl;

  if (k >= arr[pivotIndex] && k <= arr[n - 1])
  {
    cout << "Element at index: " << binarySearch(arr, pivotIndex, n - 1, k) << endl;
  }
  else
  {
    cout << "Element at index: " << binarySearch(arr, 0, pivotIndex - 1, k) << endl;
  }

  return 0;
}
