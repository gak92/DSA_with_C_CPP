/*
1752. Check if Array Is Sorted and Rotated
Easy
1.7K
80
Companies
Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.



Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<int> v)
{
  cout << "Array elements: ";
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

bool rotated_and_sorted(vector<int> nums)
{
  int n = nums.size();

  int count = 0;

  for (int i = 1; i < n; i++)
  {
    if (nums[i - 1] > nums[i])
    {
      count++;
    }
  }

  if (nums[n - 1] > nums[0])
  {
    count++;
  }

  return count <= 1;
}

int main()
{
  // vector<int> nums = {3, 4, 5, 1, 2};
  // vector<int> nums = {1, 2, 3};
  vector<int> nums = {2, 1, 3, 4};

  if (rotated_and_sorted(nums))
  {
    cout << "TRUE" << endl;
  }
  else
  {
    cout << "FALSE" << endl;
  }
  return 0;
}
