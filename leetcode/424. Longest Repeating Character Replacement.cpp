/*

https://leetcode.com/problems/longest-repeating-character-replacement/description/

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.



Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.


Constraints:

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length
*/

#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int characterReplacement(string s, int k)
  {
    unordered_map<char, int> umap;
    int left = 0;
    int res = 0;
    int maxf = 0;

    for (int right = 0; right < s.length(); right++)
    {
      umap[s[right]] = 1 + umap[s[right]];
      maxf = max(maxf, umap[s[right]]);

      if ((right - left + 1) - maxf > k)
      {
        umap[s[left]] -= 1;
        left++;
      }
      else
        res = max(res, (right - left + 1));
    }
    return res;
  }
};

int main()
{
  Solution *s = new Solution();
  string str = "ABAB";
  int k = 2;
  printf("%d\n", s->characterReplacement(str, k));
  str = "AABABBA";
  k = 1;
  printf("%d\n", s->characterReplacement(str, k));
  return 0;
}

/*

s = "ABAB", k = 2
     l
      r

umap: A = 1,2
      B = 1,2
maxf = 1
*/