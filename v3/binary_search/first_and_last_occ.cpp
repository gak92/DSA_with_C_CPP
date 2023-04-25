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
  int first_occ = first_occurrence(arr, key);
  int last_occ = last_occurrence(arr, key);

  cout << "First Occurence of " << key << " is at Index: " << first_occ << endl;
  cout << "Last Occurence of " << key << " is at Index: " << last_occ << endl;

  // To find total number of occurrences
  // last occ index - first occ index + 1
  cout << "Total number of occurrences: " << last_occ - first_occ + 1 << endl;

  return 0;
}