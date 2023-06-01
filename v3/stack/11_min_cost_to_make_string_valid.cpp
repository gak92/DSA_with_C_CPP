/*
  https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770
*/

#include <bits/stdc++.h>
using namespace std;

int findMinimumCost(string str)
{

  if (str.length() % 2 == 1)
    return -1;

  stack<char> st;

  for (int i = 0; i < str.length(); i++)
  {
    char ch = str[i];
    if (ch == '{')
    {
      st.push(ch);
    }
    else
    {
      if (!st.empty() && st.top() == '{')
      {
        st.pop();
      }
      else
      {
        st.push(ch);
      }
    }
  }

  int a = 0, b = 0;
  while (!st.empty())
  {
    if (st.top() == '{')
      b++;
    else
      a++;
    st.pop();
  }

  int res = (a + 1) / 2 + (b + 1) / 2;
  return res;
}

int main()
{
  string str = "{{{}";

  return 0;
}