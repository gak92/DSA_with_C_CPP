#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print2DArray(int arr[][4], int rows, int cols)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

void rowSum(int arr[][4], int rows, int cols)
{
  for (int i = 0; i < rows; i++)
  {
    int sum = 0;
    for (int j = 0; j < cols; j++)
    {
      sum += arr[i][j];
    }
    cout << "Row " << i << " sum is: " << sum << endl;
  }
}

void colSum(int arr[][4], int rows, int cols)
{
  for (int i = 0; i < cols; i++)
  {
    int sum = 0;
    for (int j = 0; j < rows; j++)
    {
      sum += arr[j][i];
    }
    cout << "Col " << i << " sum is: " << sum << endl;
  }
}

void largestRowSum(int arr[][4], int rows, int cols)
{
  int maximum = INT_MIN;
  int rowIndex = -1;

  for (int i = 0; i < rows; i++)
  {
    int sum = 0;
    for (int j = 0; j < cols; j++)
    {
      sum += arr[i][j];
    }
    if (sum > maximum)
    {
      maximum = sum;
      rowIndex = i;
    }
  }

  cout << "Largest Sum is: " << maximum << endl;
  cout << "Largest Sum at index: " << rowIndex << endl;
}

int main()
{

  int arr[3][4];
  // input: 1 2 3 4 5 6 7 8 9 10 11 12
  cout << "Array Input: ";
  for (int row = 0; row < 3; row++)
  {
    for (int col = 0; col < 4; col++)
    {
      cin >> arr[row][col];
    }
  }

  print2DArray(arr, 3, 4);
  cout << endl;
  // Row Wise Sum
  rowSum(arr, 3, 4);
  // Col Wise Sum
  colSum(arr, 3, 4);

  // Largest Row Sum
  largestRowSum(arr, 3, 4);

  return 0;
}