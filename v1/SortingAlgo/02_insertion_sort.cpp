#include <stdio.h>

void printArray(int *arr, int len)
{
  printf("\nArray elements are: ");
  for (int i = 0; i < len; i++)
  {
    printf(" %d", arr[i]);
  }
}

void insertion_sort(int *arr, int len)
{
  int key, j;
  for (int i = 1; i <= (len - 1); i++)
  {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }
}

int main()
{
  //        -1  0   1  2   3   4  5   6
  int arr[] = {12, 54, 65, 7, 23, 9, 19};
  // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int len = sizeof(arr) / sizeof(arr[0]);

  printf("\nLength of an array: %d", len);
  printArray(arr, len);
  insertion_sort(arr, len);
  printArray(arr, len);

  return 0;
}