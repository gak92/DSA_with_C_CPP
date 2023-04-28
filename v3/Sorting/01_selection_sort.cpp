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

void selectionSort(vector<int> arr)
{
  int n = arr.size();

  for (int i = 0; i < n - 1; i++)
  {
    int minIndex = i;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[minIndex])
      {
        minIndex = j;
      }
    }
    swap(arr[i], arr[minIndex]);
  }

  printArray(arr);
}

int main()
{
  vector<int> arr = {29, 72, 98, 13, 87, 66, 52, 51, 36};

  cout << "Sorted Array: ";
  selectionSort(arr);

  return 0;
}