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

void sort012(int arr[], int size)
{
  int left = 0, mid = 0, right = size - 1;

  while (mid <= right)
  {
    // if (mid == 0)
    // {
    //   swap(arr[left], arr[mid]);
    //   left++;
    //   mid++;
    // }
    // if (mid == 1)
    // {
    //   mid++;
    // }
    // if (mid == 2)
    // {
    //   swap(arr[mid], arr[right]);
    //   right--;
    // }

    switch (arr[mid])
    {
    case 0:
      swap(arr[left], arr[mid]);
      left++;
      mid++;
      break;
    case 1:
      mid++;
      break;
    case 2:
      swap(arr[mid], arr[right]);
      right--;
      break;
    }
  }
}

int main()
{
  int arr[8] = {1, 0, 1, 2, 0, 2, 1, 0};

  cout << "Before Sorting: ";
  print_array(arr, 8);

  sort012(arr, 8);
  cout << "After Sorting: ";
  print_array(arr, 8);

  return 0;
}