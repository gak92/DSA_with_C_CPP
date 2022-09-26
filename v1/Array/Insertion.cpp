#include <stdio.h>
// #include <iostream>
// using namespace std;

void display(int arr[], int n)
{
  // cout << "Array elements: " << endl;
  printf("Array elements: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int InsertAtIndex(int arr[], int size, int element, int index, int capacity)
{
  if (size >= capacity)
  {
    return -1;
  }
  for (int i = size - 1; i >= index; i--)
  {
    arr[i + 1] = arr[i];
  }
  arr[index] = element;
  return 1;
}

int main()
{
  int arr[100] = {1, 2, 4, 99};
  int size = 4, element = 19, index = 2;
  int isSuccess;
  // cout << "Array values are: " << endl;
  display(arr, size);

  isSuccess = InsertAtIndex(arr, size, element, index, 100);
  if (isSuccess == 1)
  {
    size += 1;
    display(arr, size);
  }
  else
  {
    printf("Array insertion failed");
  }
}