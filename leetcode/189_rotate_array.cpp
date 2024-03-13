/*
189. Rotate Array

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.


Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
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

int main()
{
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  int n = nums.size();
  int k = 3;

  vector<int> temp(n);

  for (int i = 0; i < n; i++)
  {
    temp[(i + k) % n] = nums[i];
  }

  cout << "Original Array: ";
  print_vector(nums);

  cout << "Rotated Array: ";
  print_vector(temp);

  return 0;
}
