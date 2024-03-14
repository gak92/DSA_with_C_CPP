/*
https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/

Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.



Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.


Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
1 <= k <= s.length
*/

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxVowels(string s, int k)
  {
    int left = 0, right = 0, res = 0, count = 0;
    string vowels = "aeiou";

    while (right < k)
    {
      if (vowels.find(s[right]) != string::npos)
        count++;
      right++;
    }
    res = count;
    while (right < s.length())
    {
      if (vowels.find(s[right]) != string::npos)
        count++;

      // increase left index to keep window size
      if (vowels.find(s[left]) != string::npos)
        count--;

      left++;
      right++;
      res = max(res, count);
    }
    return res;
  }
};

int main()
{
  Solution s;
  string str = "abciiidef";
  int k = 3;
  cout << s.maxVowels(str, k) << endl;
  return 0;
}