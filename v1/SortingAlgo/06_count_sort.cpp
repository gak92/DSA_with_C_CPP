#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void printArray(int *arr, int len)
{
  printf("\nArray elements are: ");
  for (int i = 0; i < len; i++)
  {
    printf(" %d", arr[i]);
  }
}

int maximum(int *arr, int len)
{
  int max = INT_MIN;
  for (int i = 0; i < len; i++)
  {
    if (arr[i] > max)
    {
      max = arr[i];
    }
  }
  return max;
}

void count_sort(int *arr, int len)
{
  int i, j;
  int max = maximum(arr, len);
  int *count = (int *)malloc((max + 1) * sizeof(int));

  for (i = 0; i < max + 1; i++)
  {
    count[i] = 0;
  }
  for (i = 0; i < len; i++)
  {
    count[arr[i]] = count[arr[i]] + 1;
  }

  i = 0;
  j = 0;
  while (i <= max)
  {
    if (count[i] > 0)
    {
      arr[j] = i;
      count[i] = count[i] - 1;
      j++;
    }
    else
    {
      i++;
    }
  }
}

int main()
{
  int arr[] = {12, 54, 65, 7, 1, 92, 23, 9, 19};
  int len = sizeof(arr) / sizeof(arr[0]);

  printf("\nLength of an array: %d", len);
  printArray(arr, len);
  count_sort(arr, len);
  printf("\nAfter count sort:");
  printArray(arr, len);

  return 0;
}