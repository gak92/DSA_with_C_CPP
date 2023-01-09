#include<iostream>
using namespace std;

int linearSearch(int arr[], int size, int key)
{
  for(int i=0; i<size; i++)
  {
    if(key == arr[i])
      return i;
  }
  return -1;
}

int binarySearch(int arr[], int size, int key)
{
  int start=0, end=size, mid;

  while(start <= end)
  {
    mid = (start + end) / 2;
    if(key == arr[mid])
      return mid;
    else if(key < arr[mid])
      end = mid - 1;
    else
      start = mid + 1;
  }
  return -1;
}

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

  cout << "Elements of an array: ";
  for(int i=0; i<size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  int key, foundIdx;
  cout << "Enter a value to search: ";
  cin >> key;

  // linear Search
  foundIdx = linearSearch(arr, size, key);
  if(foundIdx == -1)
    cout << "Element not found" << endl;
  else
    cout << "Element found at index: " << foundIdx << endl;

  // Binary Search
  foundIdx = binarySearch(arr, size, key);
  if(foundIdx == -1)
    cout << "Element not found" << endl;
  else
    cout << "Element found at index: " << foundIdx << endl;

}