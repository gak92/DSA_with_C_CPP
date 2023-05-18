/*
54. Spiral Matrix
Medium
12.1K
1.1K
Companies
Given an m x n matrix, return all elements of the matrix in spiral order.

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> matrix)
{
  vector<int> res;

  int nRows = matrix.size();
  int mCols = matrix[0].size();
  int total = nRows * mCols;
  int count = 0;

  int startingRow = 0;
  int endingRow = nRows - 1;
  int startingCol = 0;
  int endingCol = mCols - 1;

  while (count < total)
  {
    for (int i = startingCol; i <= endingCol && count < total; i++)
    {
      res.push_back(matrix[startingRow][i]);
      count++;
    }
    startingRow++;

    for (int i = startingRow; i <= endingRow && count < total; i++)
    {
      res.push_back(matrix[i][endingCol]);
      count++;
    }
    endingCol--;

    for (int i = endingCol; i >= startingCol && count < total; i--)
    {
      res.push_back(matrix[endingRow][i]);
      count++;
    }
    endingRow--;

    for (int i = endingRow; i >= startingRow && count < total; i--)
    {
      res.push_back(matrix[i][startingCol]);
      count++;
    }
    startingCol++;
  }

  return res;
}

int main()
{

  vector<vector<int>> matrix{
      {1, 2, 3, 11},
      {4, 5, 6, 12},
      {7, 8, 9, 13},
      {21, 22, 23, 24}};

  vector<int> res = spiralOrder(matrix);

  for (auto val : res)
  {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}