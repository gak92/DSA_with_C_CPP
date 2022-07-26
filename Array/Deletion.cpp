#include <stdio.h>

void display(int arr[], int n)
{
  printf("Array elements: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int DeleteAtIndex(int arr[], int size, int index, int capacity)
{
  if (index >= capacity)
  {
    return -1;
  }
  for (int i = index; i < size - 1; i++)
  {
    arr[i] = arr[i + 1];
  }
  return 1;
}

int main()
{
  int arr[100] = {1, 2, 4, 99};
  int size = 4, element = 19, index = 2;
  int isSuccess;
  display(arr, size);

  isSuccess = DeleteAtIndex(arr, size, index, 100);
  if (isSuccess == 1)
  {
    size -= 1;
    display(arr, size);
  }
  else
  {
    printf("Array deletion failed");
  }
}