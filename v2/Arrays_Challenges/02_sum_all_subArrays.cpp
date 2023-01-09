#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Sum of all SubArrays
*/

int main()
{
  int size;
  cout << "Enter the size of the array: ";
  cin >> size;

  int arr[size];
  cout << "Enter the element of the array: ";
  for(int i=0; i<size; i++)
  {
    cin >> arr[i];
  }

  int currentSum;

  for(int i=0; i<size; i++)
  {
    currentSum = 0;
    for(int j=i; j<size; j++)
    {
      currentSum += arr[j];
      cout << "Sum of SubArray: " << currentSum << endl;
    }
  }


  return 0;
}