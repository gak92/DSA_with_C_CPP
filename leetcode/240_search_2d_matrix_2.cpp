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

  int rowIndex = 0;
  int colIndex = mCols - 1;

  while (rowIndex < nRows && colIndex >= 0)
  {
    int element = matrix[rowIndex][colIndex];

    if (target == element)
    {
      return true;
    }

    if (target > element)
    {
      rowIndex++;
    }
    else
    {
      colIndex--;
    }
  }

  return false;
}

int main()
{

  vector<vector<int>> matrix{
      {1, 4, 7, 11, 15},
      {2, 5, 8, 12, 19},
      {3, 6, 9, 16, 22},
      {10, 13, 14, 17, 24},
      {18, 21, 23, 26, 30}};

  int target = 25;

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