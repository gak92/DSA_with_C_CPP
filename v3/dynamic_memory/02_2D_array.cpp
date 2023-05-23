#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter size of the array: ";
  cin >> n;

  // create 2D Array
  int **arr = new int *[n];
  for (int i = 0; i < n; i++)
  {
    arr[i] = new int[n];
  }

  // taking input
  cout << "Enter element of the 2D array: ";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> arr[i][j];
    }
  }

  // output 2D Array Element
  cout << "Elements of 2D Array" << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}