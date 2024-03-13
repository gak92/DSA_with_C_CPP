/*
https://leetcode.com/problems/subsets/description/

78. Subsets
Medium
14.5K
210
Companies
Given an integer array nums of unique elements, return all possible
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.



Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> nums, int index, vector<int> output, vector<vector<int>> &res)
{
  if (index >= nums.size())
  {
    res.push_back(output);
    return;
  }

  solve(nums, index + 1, output, res);
  output.push_back(nums[index]);
  solve(nums, index + 1, output, res);
}

vector<vector<int>> subSets(vector<int> nums)
{
  vector<vector<int>> res;
  int index = 0;
  vector<int> output;

  solve(nums, index, output, res);

  return res;
}

void printSubsets(vector<vector<int>> subsets)
{

  cout << "[ ";
  for (int i = 0; i < subsets.size(); i++)
  {
    cout << "[";
    for (int j = 0; j < subsets[i].size(); j++)
    {
      cout << subsets[i][j] << ", ";
    }
    cout << "], ";
  }
  cout << " ]" << endl;
}

int main()
{

  vector<int> nums{1, 2, 3};

  vector<vector<int>> subsets = subSets(nums);
  printSubsets(subsets);

  return 0;
}
