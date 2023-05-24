#include <iostream>
using namespace std;

void merge(int *arr, int start, int end)
{
  int mid = start + (end - start) / 2;
  int len1 = mid - start + 1;
  int len2 = end - mid;

  int *first = new int[len1];
  int *second = new int[len2];

  // copy values
  int mainArrayIndex = start;
  for (int i = 0; i < len1; i++)
  {
    first[i] = arr[mainArrayIndex++];
  }

  mainArrayIndex = mid + 1;
  for (int i = 0; i < len2; i++)
  {
    second[i] = arr[mainArrayIndex++];
  }

  // merge 2 sorted Array
  int index1 = 0;
  int index2 = 0;
  mainArrayIndex = start;

  while (index1 < len1 && index2 < len2)
  {
    if (first[index1] < second[index2])
    {
      arr[mainArrayIndex++] = first[index1++];
    }
    else
    {
      arr[mainArrayIndex++] = second[index2++];
    }
  }

  while (index1 < len1)
  {
    arr[mainArrayIndex++] = first[index1++];
  }

  while (index2 < len2)
  {
    arr[mainArrayIndex++] = second[index2++];
  }

  delete[] first;
  delete[] second;
}

void mergeSort(int *arr, int start, int end)
{
  // base case
  if (start >= end)
    return;

  int mid = start + (end - start) / 2;

  // sort left part
  mergeSort(arr, start, mid);

  // sort right part
  mergeSort(arr, mid + 1, end);

  // merge
  merge(arr, start, end);
}

int main()
{
  int size = 12;
  int arr[size] = {2, 5, 1, 6, 9, 41, 27, 19, 92, 70, 7, 3};

  mergeSort(arr, 0, size - 1);

  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}