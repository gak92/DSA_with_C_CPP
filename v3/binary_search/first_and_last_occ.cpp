#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int first_occurrence(vector<int> arr, int key)
{
  int start = 0;
  int end = arr.size() - 1;
  int mid = start + (end - start) / 2;
  int res = -1;

  while (start <= end)
  {
    if (key == arr[mid])
    {
      res = mid;
      end = mid - 1;
    }
    else if (key > arr[mid])
    {
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }

    mid = start + (end - start) / 2;
  }
  return res;
}

int last_occurrence(vector<int> arr, int key)
{
  int start = 0;
  int end = arr.size() - 1;
  int mid = start + (end - start) / 2;
  int res = -1;

  while (start <= end)
  {
    if (key == arr[mid])
    {
      res = mid;
      start = mid + 1;
    }
    else if (key > arr[mid])
    {
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }

    mid = start + (end - start) / 2;
  }
  return res;
}

int main()
{
  vector<int> arr = {1, 2, 2, 3, 3, 3, 3, 5, 5, 7};

  int key = 5;
  cout << "First Occurence of " << key << " is at Index: " << first_occurrence(arr, key) << endl;
  cout << "Last Occurence of " << key << " is at Index: " << last_occurrence(arr, key) << endl;

  return 0;
}