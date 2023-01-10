#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Print all SubArrays

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


  for(int i=0; i<size; i++)
  {
    for(int j=i; j<size; j++)
    {
      for(int k=i; k<=j; k++)
      {
        cout << arr[k] << " ";
      }
      cout << endl;
    }
  }

  return 0;
}