#include <iostream>
using namespace std;

void printArray(int arr[], int size, int start = 0)
{
  cout << "Array elements: ";
  for (int i = start; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{

  int size = 7;
  int arr[size] = {1, 2, 3, 4, 5, 6, 7};

  printArray(arr, size);

  printArray(arr, size, 3);

  return 0;
}