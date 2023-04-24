/*
442. Find All Duplicates in an Array

Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:

Input: nums = [1,1,2]
Output: [1]
Example 3:

Input: nums = [1]
Output: []
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print_array(vector<int> arr)
{
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{
  vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
  vector<int> res;
  map<int, int> mp;

  for (int i = 0; i < nums.size(); i++)
  {
    mp[nums[i]]++;
  }

  for (auto it : mp)
  {
    if (it.second > 1)
    {
      res.push_back(it.first);
    }
  }

  print_array(res);

  return 0;
}