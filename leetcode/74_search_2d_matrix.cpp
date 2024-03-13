/*
74. Search a 2D Matrix
Medium
12.2K
348
Companies
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> matrix, int target)
{
  int nRows = matrix.size();
  int mCols = matrix[0].size();
  int start = 0;
  int end = (nRows * mCols) - 1;
  int mid = start + (end - start) / 2;

  while (start <= end)
  {
    int element = matrix[mid / mCols][mid % mCols];
    if (target == element)
    {
      return true;
    }

    if (target > element)
    {
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
    mid = start + (end - start) / 2;
  }

  return false;
}

int main()
{

  vector<vector<int>> matrix{
      {1, 3, 5, 7},
      {10, 11, 16, 20},
      {23, 30, 64, 60}};

  int target = 19;

  if (searchMatrix(matrix, target))
  {
    cout << "Element found" << endl;
  }
  else
  {
    cout << "Element not found" << endl;
  }

  return 0;
}