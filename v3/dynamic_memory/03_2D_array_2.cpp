#include <iostream>
using namespace std;

int main()
{
  int row, col;
  cout << "Enter number of rows: ";
  cin >> row;
  cout << "Enter number of cols: ";
  cin >> col;

  // create 2D Array
  int **arr = new int *[row];
  for (int i = 0; i < row; i++)
  {
    arr[i] = new int[col];
  }

  // taking input
  cout << "Enter element of the 2D array: ";
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      cin >> arr[i][j];
    }
  }

  // output 2D Array Element
  cout << "Elements of 2D Array" << endl;
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  // Releasing Memory
  for (int i = 0; i < row; i++)
  {
    delete[] arr[i];
  }
  delete[] arr;

  return 0;
}