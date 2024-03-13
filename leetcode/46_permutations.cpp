/*
https://leetcode.com/problems/permutations/description/

46. Permutations
Medium
15.7K
256
Companies
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.



Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<vector<int>> v)
{

  cout << "[ ";
  for (int i = 0; i < v.size(); i++)
  {
    cout << "[";
    for (int j = 0; j < v[i].size(); j++)
    {
      cout << v[i][j] << ", ";
    }
    cout << "], ";
  }
  cout << " ]" << endl;
}

void permutations(vector<int> nums, int index, vector<vector<int>> &res)
{
  if (index >= nums.size())
  {
    res.push_back(nums);
    return;
  }

  for (int i = index; i < nums.size(); i++)
  {
    swap(nums[index], nums[i]);
    permutations(nums, index + 1, res);

    // backtrack
    swap(nums[index], nums[i]);
  }
}

int main()
{
  vector<int> nums{1, 2, 3};
  vector<vector<int>> res;
  int index = 0;

  permutations(nums, index, res);
  printVector(res);

  return 0;
}
