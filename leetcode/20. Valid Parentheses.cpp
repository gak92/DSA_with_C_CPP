/*

https://leetcode.com/problems/valid-parentheses/description/

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.


Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false


Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isValid(string s)
  {
    stack<char> st;
    unordered_map<char, char> brackets = {
        {'(', ')'},
        {'{', '}'},
        {'[', ']'}};

    for (int i = 0; i < s.size(); i++)
    {
      if (brackets.find(s[i]) != brackets.end())
        st.push(s[i]);
      else
      {
        if (st.empty())
          return false;
        char ch = st.top();
        st.pop();
        if (s[i] != brackets[ch])
          return false;
      }
    }

    if (st.empty())
      return true;
    else
      return false;
  }
};

int main()
{
  Solution s;
  string str = "()";
  cout << s.isValid(str) << endl;
  str = "()[]{}";
  cout << s.isValid(str) << endl;
  str = "(]";
  cout << s.isValid(str) << endl;
  return 0;
}