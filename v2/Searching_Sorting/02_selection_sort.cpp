#include<iostream>
using namespace std;

/*
SELECTION SORT:
  Find the minimum element in the unsorted array and
  swap it with the element at the begining.
*/

int main()
{
  int size;
  cout << "Enter the size of the array: ";
  cin >> size;

  int arr[size];
  cout << "Enter the element of the array: ";
  for(int i=0; i<size; i++)
  {
    cin >> arr[i];
  }

  for(int i=0; i<size-1; i++)
  {
    for(int j=i+1; j<size; j++)
    {
      if(arr[j] < arr[i])
      {
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
      }
    }
  }

  cout << "Array after Selection Sort: ";
  for(int i=0; i<size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}