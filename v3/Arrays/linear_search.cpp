#include <iostream>
#include <climits>
using namespace std;

bool linear_search(int arr[], int size, int key)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == key)
    {
      return 1;
    }
  }
  return 0;
}

int main()
{
  int arr[10] = {5, 7, -2, 10, 22, -2, 0, 5, 22, 1};
  cout << "Enter the element to search for: ";
  int key;
  cin >> key;

  bool found = linear_search(arr, 10, key);

  if (found)
  {
    cout << "Key found" << endl;
  }
  else
  {
    cout << "Key not found" << endl;
  }

  return 0;
}