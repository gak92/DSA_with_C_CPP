#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> arr, int n, int m, int mid)
{
  int studentCount = 1;
  int pageSum = 0;

  for (int i = 0; i < n; i++)
  {
    if (pageSum + arr[i] <= mid)
    {
      pageSum += arr[i];
    }
    else
    {
      studentCount++;
      if (studentCount > m || arr[i] > mid)
      {
        return false;
      }
      pageSum = arr[i];
    }
  }
  return true;
}

int allocateBooks(vector<int> arr, int n, int m)
{
  int start = 0;
  int sum = 0;
  int res = -1;

  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
  }

  int end = sum;
  int mid = start + (end - start) / 2;

  while (start <= end)
  {
    if (isPossible(arr, n, m, mid))
    {
      res = mid;
      end = mid - 1;
    }
    else
    {
      start = mid + 1;
    }
    mid = start + (end - start) / 2;
  }
  return res;
}

int main()
{
  // vector<int> arr = {30, 20, 10, 40, 5, 45}; // Number of pages in each book
  vector<int> arr = {1, 2, 2, 3, 1};
  int n = arr.size(); // Number of books (length of array)
  int m = 3;          // Number of students;

  cout << "Minimum number of pages: " << allocateBooks(arr, n, m) << endl;

  return 0;
}