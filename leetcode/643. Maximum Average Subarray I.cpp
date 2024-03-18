/*

https://leetcode.com/problems/maximum-average-subarray-i/description/
*/

#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  double findMaxAverage(vector<int> &nums, int k)
  {
    int left = 0;
    double total = 0;

    for (int right = 0; right < k; right++)
      total += nums[right];
    double maximum = total;

    for (int right = k; right < nums.size(); right++)
    {
      total -= nums[left];
      total += nums[right];

      left++;
      maximum = max(maximum, total);
    }

    return (maximum / k);
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 12, -5, -6, 50, 3};
  int k = 4;
  printf("%f\n", s.findMaxAverage(nums, k));
  return 0;
}