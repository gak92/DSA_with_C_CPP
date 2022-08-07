#include <stdio.h>

void printArray(int *arr, int len)
{
  printf("\nArray elements are: ");
  for (int i = 0; i < len; i++)
  {
    printf(" %d", arr[i]);
  }
}

void bubble_sort(int *arr, int len)
{
  int temp;
  int isSorted = 0;
  for (int i = 0; i < len - 1; i++)
  {
    printf("\nRun pass # %d", i + 1);
    isSorted = 1;
    for (int j = 0; j < len - 1 - i; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        isSorted = 0;
      }
    }
    if (isSorted)
    {
      return;
    }
  }
}

int main()
{
  // int arr[] = {12, 54, 65, 7, 23, 9, 19};
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int len = sizeof(arr) / sizeof(arr[0]);

  printf("\nLength of an array: %d", len);
  printArray(arr, len);
  bubble_sort(arr, len);
  printArray(arr, len);

  return 0;
}