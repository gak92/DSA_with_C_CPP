#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
SubArray with given sum

Given an unsorted array A of size N of non-negative integers, find a continuous
subarray which adds to a given number S.

Enter the size of the array: 5
Enter the element of the array: 1 2 3 7 5
Enter the target sum: 12
Index from 2 to 4 has target sum

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

  int targetSum;
  cout << "Enter the target sum: ";
  cin >> targetSum;

  // Two pointers approach (optimized)
  int i=0, j=0;
  int start=-1, end=-1;
  int currentSum=0;

  while(j<size && currentSum+arr[j] <= targetSum)
  {
    currentSum += arr[j];
    j++;
  }
  if(currentSum == targetSum)
  {
    cout << "Index from " << i+1 << " to " << j << " has target sum" << endl;
    return 0;
  }

  while(j<size)
  {
    currentSum += arr[j];
    while(currentSum > targetSum)
    {
      currentSum -= arr[i];
      i++;
    }

    if(currentSum == targetSum)
    {
      start = i+1;
      end = j+1;
      break;
    }
    j++;
  }

  cout << "Index from " << start << " to " << end << " has target sum" << endl;

  return 0;
}