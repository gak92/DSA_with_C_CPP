#include <stdio.h>

int LinearSearch(int arr[], int size, int element)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == element)
    {
      return i;
    }
  }
  return -1;
}

int BinarySearch(int arr[], int size, int element)
{
  int low = 0, mid, high = size;

  while (low <= high)
  {
    mid = (low + high) / 2;
    if (arr[mid] == element)
    {
      return mid;
    }
    if (arr[mid] < element)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return -1;
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 99, 56, 72, 92, 101, 548, 78, 458, 5};
  int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 19, 27, 41, 70, 92, 99, 101, 111, 140, 313};
  int size = sizeof(arr) / sizeof(int);
  int size2 = sizeof(arr2) / sizeof(int);
  int element = 99, element2 = 1;
  int linsearchIndex = LinearSearch(arr, size, element);
  int binsearchIndex = BinarySearch(arr2, size2, element2);

  printf("Linear Search\n");
  if (linsearchIndex != -1)
  {
    printf("Element %d found at %d\n", element, linsearchIndex);
  }
  else
  {
    printf("Element not found\n");
  }

  printf("Binary Search\n");
  if (binsearchIndex != -1)
  {
    printf("Element %d found at %d\n", element2, binsearchIndex);
  }
  else
  {
    printf("Element not found");
  }

  return 0;
}