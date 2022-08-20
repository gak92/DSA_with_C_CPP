#include <stdio.h>

void printArray(int *arr, int len)
{
  printf("\nArray elements are: ");
  for (int i = 0; i < len; i++)
  {
    printf(" %d", arr[i]);
  }
}

void selection_sort(int *arr, int len)
{
  printf("\nAfter Selection sort:");
  int index_of_min, temp;
  for (int i = 0; i < len - 1; i++)
  {
    index_of_min = i;
    for (int j = i + 1; j < len; j++)
    {
      if (arr[j] < arr[index_of_min])
      {
        index_of_min = j;
      }
    }
    // swapping
    temp = arr[i];
    arr[i] = arr[index_of_min];
    arr[index_of_min] = temp;
  }
}

int main()
{
  int arr[] = {12, 54, 65, 7, 23, 9, 19};
  int len = sizeof(arr) / sizeof(arr[0]);

  printf("\nLength of an array: %d", len);
  printArray(arr, len);
  selection_sort(arr, len);
  printArray(arr, len);

  return 0;
}