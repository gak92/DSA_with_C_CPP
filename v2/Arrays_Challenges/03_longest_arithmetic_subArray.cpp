#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Longest Arithmetic Sub Array

  Enter the size of the array: 7
  Enter the element of the array: 10 7 4 6 8 10 11
  Longest Arithmetic Sub Array: 4
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

  int longest_subarray;
  int previous_difference = arr[1] - arr[0];
  int i = 2;
  int current_subarray = 2;

  while(i < size)
  {
    if(previous_difference == arr[i] - arr[i-1])    // if difference is same
    {
      current_subarray++;
    }
    else
    {
      previous_difference = arr[i] - arr[i-1];
      current_subarray = 2;     // reinitialize current longest subarray
    }
    longest_subarray = max(longest_subarray, current_subarray);   // update longest subarray
    i++;
  }

  cout << "Longest Arithmetic Sub Array: " << longest_subarray << endl;

  return 0;
}