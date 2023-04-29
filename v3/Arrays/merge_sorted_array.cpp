#include <iostream>
using namespace std;

void mergeSortedArray(int arr[], int brr[], int n, int m, int merge[])
{
  int i = 0, j = 0, k = 0;

  while (i < n && j < m)
  {
    if (arr[i] < brr[j])
    {
      merge[k] = arr[i];
      k++;
      i++;
    }
    else
    {
      merge[k] = brr[j];
      k++;
      j++;
    }
  }

  while (i < n)
  {
    merge[k] = arr[i];
    k++;
    i++;
  }

  while (j < m)
  {
    merge[k] = arr[j];
    k++;
    j++;
  }
}

void print_array(int arr[], int size)
{
  cout << "Array elements: ";
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{
  int arr[5] = {1, 3, 5, 7, 9};
  int brr[4] = {2, 4, 6, 8};

  cout << "First Sorted Array: ";
  print_array(arr, 5);

  cout << "Second Sorted Array: ";
  print_array(brr, 4);

  int merge[9] = {0};
  mergeSortedArray(arr, brr, 5, 4, merge);

  cout << "Merged Sorted Array: ";
  print_array(merge, 9);

  cout << endl;

  return 0;
}