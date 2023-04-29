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

void insertionSort(vector<int> arr)
{
  int n = arr.size();

  for (int i = 1; i < n; i++)
  {
    int temp = arr[i];
    int j = i - 1;
    for (; j >= 0; j--)
    {
      if (arr[j] > temp)
      {
        arr[j + 1] = arr[j];
      }
      else
      {
        break;
      }
    }
    arr[j + 1] = temp;
  }

  printArray(arr);
}

int main()
{
  vector<int> arr = {29, 72, 98, 13, 101, 87, 66, 52, 51, 36};

  cout << "Sorted Array: ";
  insertionSort(arr);

  return 0;
}