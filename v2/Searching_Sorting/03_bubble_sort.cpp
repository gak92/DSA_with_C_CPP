#include<iostream>
using namespace std;

/*
BUBBLE SORT:
  Repeatedly swap two adjacent elements if they are in wrong order.
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

  int counter = 1;
  while(counter < size)
  {
    for(int i=0; i<size-counter; i++)
    {
      if(arr[i] > arr[i+1])
      {
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
      }
    }
    counter++;
  }
  

  cout << "Array after Bubble Sort: ";
  for(int i=0; i<size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}