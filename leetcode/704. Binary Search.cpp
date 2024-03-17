/*
https://leetcode.com/problems/binary-search/description/

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1


Constraints:

1 <= nums.length <= 104
-104 < nums[i], target < 104
All the integers in nums are unique.
nums is sorted in ascending order.
*/

#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int search(vector<int> &nums, int target)
  {
    int start = 0;
    int end = nums.size() - 1;

    while (start <= end)
    {
      int mid = (start + end) / 2;

      if (target == nums[mid])
        return mid;
      else if (target > nums[mid])
        start = mid + 1;
      else
        end = mid - 1;
    }

    return -1;
  }
};

int main()
{
  vector<int> nums = {-1, 0, 3, 5, 9, 12};
  int target = 9;
  Solution s;
  printf("%d\n", s.search(nums, target));
  return 0;
}