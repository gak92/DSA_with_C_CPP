#include <iostream>
using namespace std;

void bubbleSort(int *arr, int size)
{
  // base case - Array already sorted
  if (size == 0 || size == 1)
    return;

  // processing - solve single case
  for (int i = 0; i < size - 1; i++)
  {
    if (arr[i] > arr[i + 1])
    {
      swap(arr[i], arr[i + 1]);
    }
  }

  // recursive call
  bubbleSort(arr, size - 1);
}

int main()
{
  int size = 10;
  int arr[size] = {2, 5, 1, 6, 9, 41, 27, 19, 92, 70};

  bubbleSort(arr, size);

  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}