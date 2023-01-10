#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
First Repeating Element index

Given an array arr[] of size N. The task is to find the first repeating element in an
array of integers, i.e., an element that occurs more than once and whose index of
first occurrence is smallest.

*/

int main()
{
  int size;
  cout << "Enter the size of the array: ";
  cin >> size;

  int arr[size+1];
  cout << "Enter the element of the array: ";
  for(int i=0; i<size; i++)
  {
    cin >> arr[i];
  }

  const int N = 1e6+2;
  int idx[N];
  for(int i=0; i<N; i++)
  {
    idx[i] = -1;
  }

  int min_index = INT_MAX;
  for(int i=0; i<size; i++)
  {
    if(idx[arr[i]] == -1)
    {
      idx[arr[i]] = i;
    }
    else
    {
      min_index = min(min_index, idx[arr[i]]);
    }
  }

  if(min_index == INT_MAX)
  {
    cout << "No repeating element" << endl;
  }
  else
  {
    cout << "First repeating element at index: " << min_index << endl;
  }


  return 0;
}