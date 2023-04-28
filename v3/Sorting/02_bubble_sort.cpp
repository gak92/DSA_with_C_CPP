#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> arr)
{
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
}

void bubbleSort(vector<int> arr)
{
  int n = arr.size();

  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
      }
    }
  }

  printArray(arr);
}

int main()
{
  vector<int> arr = {29, 72, 98, 13, 101, 87, 66, 52, 51, 36};

  cout << "Sorted Array: ";
  bubbleSort(arr);

  return 0;
}