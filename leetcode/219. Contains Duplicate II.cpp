/*
https://leetcode.com/problems/contains-duplicate-ii/description/
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.



Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false


Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105
*/

#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k)
  {
    int left = 0;
    unordered_set<int> set;

    for (int right = 0; right < nums.size(); right++)
    {
      if (right - left > k) // greater than window size
      {
        set.erase(nums[left]);
        left++;
      }

      if (set.find(nums[right]) != set.end())
        return true;

      set.insert(nums[right]);
    }

    return false;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 2, 3, 1};
  int k = 3;
  bool output = s.containsNearbyDuplicate(nums, k);
  printf("Output: %d", output);
  return 0;
}