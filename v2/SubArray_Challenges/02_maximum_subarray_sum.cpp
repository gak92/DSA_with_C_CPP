#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Maximum SubArray Sum
  Find the subArray in an array which has maximum sum.

Enter the size of the array: 4
Enter the element of the array: -1 4 7 2
Max SubArray Sum: 13

Enter the size of the array: 5
Enter the element of the array: -1 4 -6 7 -4
Brute Force: 
Max SubArray Sum: 7
Cumm Sum: 
Max SubArray Sum is: 7
Kadane Algo
Max SubArray Sum: 7

*/

// Brute Force approach O(N^3)
void brute_force(int arr[], int size)
{
  int max_sum = INT_MIN;

  for(int i=0; i<size; i++)
  {
    for(int j=i; j<size; j++)
    {
      int sum = 0;
      for(int k=i; k<=j; k++)
      {
        sum += arr[k];
      }
      max_sum = max(max_sum, sum);
    }
  }

  cout << "Max SubArray Sum: " << max_sum << endl;

}

void cumm_summ(int arr[], int size)
{
  // Cummulative Sum Approach O(N^2)
  int currSum[size+1];
  currSum[0] = 0;

  for(int i=1; i<=size; i++)
  {
    currSum[i] = currSum[i-1] + arr[i-1];
  }

  int maxSum = INT_MIN;
  for(int i=1; i<=size; i++)
  {
    int sum = 0;
    for(int j=0; j<i; j++)
    {
      sum = currSum[i] - currSum[j];
      maxSum = max(sum, maxSum);
    }
  }

  cout << "Max SubArray Sum is: " << maxSum << endl;

}

void kadane_algo(int arr[], int size)
{
  int currentSum = 0;
  int maxSum = INT_MIN;

  for(int i=0; i<size; i++)
  {
    currentSum += arr[i];
    if(currentSum < 0)
    {
      currentSum = 0;
    }
    maxSum = max(maxSum, currentSum);
  }
  cout << "Max SubArray Sum: " << maxSum << endl;
}

int main()
{
  // Gettin input an Array
  int size;
  cout << "Enter the size of the array: ";
  cin >> size;

  int arr[size];
  cout << "Enter the element of the array: ";
  for(int i=0; i<size; i++)
  {
    cin >> arr[i];
  }

  cout << "Brute Force: " << endl;
  brute_force(arr, size);

  cout << "Cumm Sum: " << endl;
  cumm_summ(arr, size);

  cout << "Kadane Algo" << endl;
  kadane_algo(arr, size);
  

  return 0;
}