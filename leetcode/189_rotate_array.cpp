/*
189. Rotate Array
https://leetcode.com/problems/rotate-array/description/

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
// ==========================
// Solution using extra space
// ==========================

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

// ==================================
// Solution using reverse
// ==================================

class Solution
{
public:
  void reverse(vector<int> &nums, int left, int right)
  {
    int temp;
    while (left <= right)
    {
      temp = nums[left];
      nums[left] = nums[right];
      nums[right] = temp;
      left++;
      right--;
    }
  }

  void rotate(vector<int> &nums, int k)
  {
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    k = k % n;

    reverse(nums, left, right); // reverse whole array
    reverse(nums, 0, k - 1);    // reverse from start to k - 1
    reverse(nums, k, n - 1);    // reverse remaining

    // for(int i=0; i<n; i++)
    //     cout << nums[i] << ", ";
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  int k = 3;
  s.rotate(nums, k);
  return 0;
}