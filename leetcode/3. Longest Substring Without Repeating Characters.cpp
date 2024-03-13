/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

Given a string s, find the length of the longest
substring
 without repeating characters.



Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/
#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    int left = 0;
    int maxLength = 0;
    unordered_set<char> set;

    for (int right = 0; right < s.length(); right++)
    {
      while (set.find(s[right]) != set.end())
      {
        set.erase(s[left]);
        left++;
      }

      set.insert(s[right]);
      maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
  }
};

int main()
{
  Solution s;
  string str = "abcabcbb";
  printf("%d\n", s.lengthOfLongestSubstring(str));
  return 0;
}