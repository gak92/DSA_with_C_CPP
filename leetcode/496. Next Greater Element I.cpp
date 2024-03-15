/*
https://leetcode.com/problems/next-greater-element-i/description/

The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.



Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
Example 2:

Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.


Constraints:

1 <= nums1.length <= nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 104
All integers in nums1 and nums2 are unique.
All the integers of nums1 also appear in nums2.


Follow up: Could you find an O(nums1.length + nums2.length) solution?
*/

#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
  {
    // Solution # 02 (Using Stack - Optimized)
    int n1 = nums1.size();
    vector<int> res(n1, -1);
    unordered_map<int, int> nums1Idx;
    stack<int> st;

    for (int i = 0; i < n1; i++)
      nums1Idx[nums1[i]] = i;

    for (int i = 0; i < nums2.size(); i++)
    {
      // check if current value is the next greater for all previous elements in stack
      int curr = nums2[i];
      while (!st.empty() && curr > st.top())
      {
        int val = st.top(); // curr is next greater value for val
        st.pop();
        int idx = nums1Idx[val]; // get index of the val
        res[idx] = curr;         // update next greater element(curr) for val
      }
      if (nums1Idx.find(curr) != nums1Idx.end())
        st.push(curr);
    }

    return res;

    // =========================================================
    // Solution # 01 (Using two for loop)
    // vector<int> res(nums1.size());
    // unordered_map<int,int> umap;

    // for(int i=0; i<nums1.size(); i++)
    //     umap[nums1[i]] = i;

    // for(int i=0; i<nums2.size(); i++)
    // {
    //     if(umap.find(nums2[i]) != umap.end())
    //     {
    //         for(int j=i+1; j<nums2.size(); j++)
    //         {
    //             if(nums2[j] > nums2[i])
    //             {
    //                 res[umap[nums2[i]]] = nums2[j];
    //                 break;
    //             }
    //         }
    //         if(res[umap[nums2[i]]] == 0)
    //             res[umap[nums2[i]]] = -1;
    //     }
    // }

    // return res;
  }
};

int main()
{
  vector<int> nums1 = {4, 1, 2};
  vector<int> nums2 = {1, 3, 4, 2};

  Solution s;
  vector<int> res = s.nextGreaterElement(nums1, nums2);
  for (int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
  cout << endl;

  return 0;
}