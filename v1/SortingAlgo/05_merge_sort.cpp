#include <stdio.h>

void printArray(int *arr, int len)
{
  printf("\nArray elements are: ");
  for (int i = 0; i < len; i++)
  {
    printf(" %d", arr[i]);
  }
}

void merge(int *arr, int low, int mid, int high)
{
  int new_arr[high + 1];
  int i, j, k;
  i = low;
  j = mid + 1;
  k = low;

  while (i <= mid && j <= high)
  {
    if (arr[i] < arr[j])
    {
      new_arr[k] = arr[i];
      k++;
      i++;
    }
    else
    {
      new_arr[k] = arr[j];
      k++;
      j++;
    }
  }
  while (i <= mid)
  {
    new_arr[k] = arr[i];
    k++;
    i++;
  }
  while (j <= high)
  {
    new_arr[k] = arr[j];
    k++;
    j++;
  }
  for (i = low; i <= high; i++)
  {
    arr[i] = new_arr[i];
  }
}

void merge_sort(int *arr, int low, int high)
{
  int mid;

  if (low < high)
  {
    mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
  }
}

int main()
{
  int arr[] = {12, 54, 65, 7, 1, 92, 23, 9, 19};
  int len = sizeof(arr) / sizeof(arr[0]);

  printf("\nLength of an array: %d", len);
  printArray(arr, len);
  merge_sort(arr, 0, len - 1);
  printf("\nAfter merge sort:");
  printArray(arr, len);

  return 0;
}