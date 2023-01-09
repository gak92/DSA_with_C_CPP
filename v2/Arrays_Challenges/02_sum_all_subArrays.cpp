#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Sum of all SubArrays

Enter the size of the array: 5
Enter the element of the array: 1 2 0 7 2
Sum of SubArray: 1
Sum of SubArray: 3
Sum of SubArray: 3
Sum of SubArray: 10
Sum of SubArray: 12
Sum of SubArray: 2
Sum of SubArray: 2
Sum of SubArray: 9
Sum of SubArray: 11
Sum of SubArray: 0
Sum of SubArray: 7
Sum of SubArray: 9
Sum of SubArray: 7
Sum of SubArray: 9
Sum of SubArray: 2
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