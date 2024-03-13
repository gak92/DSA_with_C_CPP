/*
88. Merge Sorted Array
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
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

void mergeSortedArray(vector<int> nums1, int m, vector<int> nums2, int n)
{
  int i = m - 1;
  int j = n - 1;
  int k = m + n - 1;

  while (i >= 0 && j >= 0)
  {
    cout << "Comparing... " << nums1[i] << " > " << nums2[j] << endl;
    if (nums1[i] > nums2[j])
    {
      nums1[k] = nums1[i];
      k--;
      i--;
    }
    else
    {
      nums1[k] = nums2[j];
      k--;
      j--;
    }
  }

  while (j >= 0)
  {
    nums1[k] = nums2[j];
    k--;
    j--;
  }

  print_vector(nums1);
}

int main()
{
  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  int m = 3;
  vector<int> nums2 = {2, 5, 6};
  int n = 3;

  cout << "First Array: ";
  print_vector(nums1);

  cout << "Second Array: ";
  print_vector(nums2);

  cout << "Merged Sorted Array: ";
  mergeSortedArray(nums1, m, nums2, n);

  return 0;
}
