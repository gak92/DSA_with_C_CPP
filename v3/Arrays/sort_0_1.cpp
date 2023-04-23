#include <iostream>
using namespace std;

void print_array(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void sort01(int arr[], int size)
{
  int left = 0, right = size - 1;

  while (left < right)
  {
    while (arr[left] == 0 && left < right)
    {
      left++;
    }
    while (arr[right] == 1 && left < right)
    {
      right--;
    }
    if (left < right)
    {
      swap(arr[left], arr[right]);
      left++;
      right--;
    }
  }
}

int main()
{
  int arr[8] = {1, 0, 1, 0, 0, 1, 1, 0};

  cout << "Before Sorting: ";
  print_array(arr, 8);

  sort01(arr, 8);
  cout << "After Sorting: ";
  print_array(arr, 8);

  return 0;
}