/*
283. Move Zeroes

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
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
  vector<int> nums = {0, 1, 0, 3, 12};

  print_vector(nums);
  int i = 0;

  for (int j = 0; j < nums.size(); j++)
  {
    if (nums[j] != 0)
    {
      swap(nums[j], nums[i]);
      i++;
    }
  }

  print_vector(nums);

  return 0;
}
