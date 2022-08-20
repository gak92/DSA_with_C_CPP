#include <stdio.h>

void printArray(int *arr, int len)
{
  printf("\nArray elements are: ");
  for (int i = 0; i < len; i++)
  {
    printf(" %d", arr[i]);
  }
}

int partition(int *arr, int low, int high)
{
  int temp;
  int pivot = arr[low];
  int i = low + 1;
  int j = high;

  do
  {
    while (arr[i] <= pivot)
    {
      i++;
    }
    while (arr[j] > pivot)
    {
      j--;
    }
    if (i < j)
    {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  } while (i < j);

  temp = arr[low];
  arr[low] = arr[j];
  arr[j] = temp;

  return j;
}

void quick_sort(int *arr, int low, int high)
{
  int partition_index;

  if (low < high)
  {
    partition_index = partition(arr, low, high);
    quick_sort(arr, low, partition_index - 1);
    quick_sort(arr, partition_index + 1, high);
  }
}

int main()
{
  int arr[] = {12, 54, 65, 7, 23, 9, 19};
  int len = sizeof(arr) / sizeof(arr[0]);

  printf("\nLength of an array: %d", len);
  printArray(arr, len);
  quick_sort(arr, 0, len - 1);
  printArray(arr, len);

  return 0;
}