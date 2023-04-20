#include <iostream>
using namespace std;

void print_array(int arr[], int size)
{
  cout << "Array elements: ";
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void swap_alternate(int arr[], int size)
{
  for (int i = 0; i < size; i += 2)
  {
    if (i + 1 < size)
    {
      swap(arr[i], arr[i + 1]);
    }
  }
}

int main()
{
  int arr[6] = {1, 2, 3, 4, 5, 6};
  int brr[5] = {11, 12, 13, 14, 15};

  swap_alternate(arr, 6);
  print_array(arr, 6);

  swap_alternate(brr, 5);
  print_array(brr, 5);

  return 0;
}