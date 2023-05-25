#include <iostream>
using namespace std;

int partition(int *arr, int start, int end)
{
  int pivot = arr[start];

  int count = 0;
  for (int i = start + 1; i <= end; i++)
  {
    if (arr[i] <= pivot)
      count++;
  }

  // place pivot at right index
  int pivotIndex = start + count;
  swap(arr[pivotIndex], arr[start]);

  int i = start, j = end;
  while (i < pivotIndex && j > pivotIndex)
  {
    while (arr[i] <= pivot)
    {
      i++;
    }
    while (arr[j] > pivot)
    {
      j--;
    }

    if (i < pivotIndex && j > pivotIndex)
    {
      swap(arr[i++], arr[j--]);
    }
  }
  return pivotIndex;
}

void quickSort(int *arr, int start, int end)
{
  // base case
  if (start >= end)
    return;

  int p = partition(arr, start, end);

  // sort left part
  quickSort(arr, start, p - 1);
  // sort right part

  quickSort(arr, p + 1, end);
}

int main()
{
  int arr[] = {2, 5, 1, 6, 9, 41, 27, 6, 5, 19, 92, 70, 7, 3};
  int size = sizeof(arr) / sizeof(arr[0]);

  quickSort(arr, 0, size - 1);

  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}