#include<bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string expression)
{
  // Write your code here.
  stack<char> st;

  for (int i = 0; i < expression.length(); i++)
  {
    char ch = expression[i];
    if (ch == '(' || ch == '{' || ch == '[')
    {
      st.push(ch);
    }
    else
    {
      if (!st.empty())
      {
        char top = st.top();
        if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '['))
        {
          st.pop();
        }
        else
        {
          return false;
        }
      }
      else
      {
        return false;
      }
    }
  }

  if (st.empty())
    return true;
  else
    return false;
}

int main()
{

  return 0;
}