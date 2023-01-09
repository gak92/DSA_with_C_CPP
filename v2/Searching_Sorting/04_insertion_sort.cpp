#include<iostream>
using namespace std;

/*
INSERTION SORT:
  Insert an element from unsorted array to its correct position in sorted array.
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

  for(int i=1; i<size; i++)
  {
    int current = arr[i];
    int j = i-1;
    while(j >= 0 && arr[j] > current)
    {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = current;
  }


  cout << "Array after Insertion Sort: ";
  for(int i=0; i<size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}