/*
https://leetcode.com/problems/subsets/

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

class Solution
{
public:
  vector<vector<int>> subsets(vector<int> &nums)
  {
    vector<vector<int>> res;
    res.push_back({});

    for (int num : nums)
    {
      int size = res.size();
      for (int j = 0; j < size; j++)
      {
        vector<int> subset = res[j]; // copy existing subset
        subset.push_back(num);       // add new num into subset
        res.push_back(subset);       // add again into result
      }
    }

    return res;
  }
};

int main()
{
  vector<int> nums = {1, 2, 3};
  Solution s;
  vector<vector<int>> res = s.subsets(nums);

  cout << "[ ";
  for (int i = 0; i < res.size(); i++)
  {
    cout << "[";
    for (int j = 0; j < res[i].size(); j++)
    {
      cout << res[i][j] << ", ";
    }
    cout << "], ";
  }
  cout << " ]" << endl;
  return 0;
}