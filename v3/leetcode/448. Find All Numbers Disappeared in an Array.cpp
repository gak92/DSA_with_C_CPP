/*
https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/

Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
Example 2:

Input: nums = [1,1]
Output: [2]
*/

#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> findDisappearedNumbers(vector<int> &nums)
  {

    // Optimized: time=O(n) space=O(1)
    vector<int> res;
    // Input: nums = [4,3,2,7,8,2,3,1]
    // nums[4-1] = - nums[4-1]
    for (auto num : nums)
      nums[abs(num) - 1] = -abs(nums[abs(num) - 1]);

    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] > 0)
        res.push_back(i + 1);
    }
    return res;

    // Here used the extra space
    // vector<int> res;
    // vector<int> check(nums.size() + 1);

    // for(auto num:nums)
    //     check[num] = 1;

    // for(int i=1; i<=nums.size(); i++)
    // {
    //     if(check[i] == 0)
    //         res.push_back(i);
    // }
    // return res;

    // Brute Force -- ()Time Limit Exceed)
    // vector<int> res;
    // for(int i=1; i<=nums.size(); i++)
    // {
    //     if(find(nums.begin(), nums.end(), i) == nums.end())
    //         res.push_back(i);
    // }
    // return res;
  }
};

int main()
{
  vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
  Solution obj;
  vector<int> res = obj.findDisappearedNumbers(nums);
  for (auto i : res)
    cout << i << " ";
  return 0;
}