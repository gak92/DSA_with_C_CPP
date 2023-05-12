#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
  for (int col = 0; col < mCols; col++)
  {
    if (col & 1)
    {
      // odd -- bottom to top
      for (int row = nRows - 1; row >= 0; row--)
      {
        cout << arr[row][col] << " ";
      }
    }
    else
    {
      // even -- top to bottom
      for (int row = 0; row < nRows; row++)
      {
        cout << arr[row][col] << " ";
      }
    }
  }
}

int main()
{

  vector<vector<int>> arr{
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12}};

  wavePrint(arr, arr.size(), arr[0].size());

  return 0;
}