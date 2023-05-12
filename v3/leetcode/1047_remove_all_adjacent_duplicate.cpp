/*
1047. Remove All Adjacent Duplicates In String
Easy
5.7K
221
Companies
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.



Example 1:

Input: s = "abbaca"
Output: "ca"
Explanation:
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
Example 2:

Input: s = "azxxzy"
Output: "ay"
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string s)
{
  stack<char> st;
  int n = s.length();

  for (int i = 0; i < n; i++)
  {
    if (!st.empty() && st.top() == s[i])
    {
      st.pop();
    }
    else
    {
      st.push(s[i]);
    }
  }

  string res = "";
  while (!st.empty())
  {
    res += st.top();
    st.pop();
  }
  reverse(res.begin(), res.end());
  return res;
}

int main()
{
  // string s = "abbaca";
  string s = "azxxzy";

  cout << "Resultant string: " << removeDuplicates(s) << endl;

  return 0;
}