/*
https://leetcode.com/problems/valid-anagram/description/

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false


Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.


Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
*/

#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    if (s.length() != t.length())
      return false;

    unordered_map<char, int> freq;

    for (char ch : s)
      freq[ch] = freq[ch] + 1;

    for (char ch : t)
    {
      if (freq.find(ch) == freq.end() || freq[ch] == 0)
        return false;

      freq[ch] = freq[ch] - 1;
    }

    return true;
  }
};

int main()
{
  Solution s;
  string str1 = "anagram";
  string str2 = "nagaram";
  printf("%d\n", s.isAnagram(str1, str2));
  return 0;
}