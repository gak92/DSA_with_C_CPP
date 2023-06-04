/*
  https://www.codingninjas.com/codestudio/problems/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465
*/

#include <bits/stdc++.h>
using namespace std;

class SpecialStack
{
  // Define the data members.
  stack<int> st;
  int mini;

  /*----------------- Public Functions of SpecialStack -----------------*/
public:
  void push(int data)
  {
    // Implement the push() function.
    if (st.empty())
    {
      st.push(data);
      mini = data;
    }
    else
    {
      if (data < mini)
      {
        st.push(2 * data - mini);
        mini = data;
      }
      else
      {
        st.push(data);
      }
    }
  }

  int pop()
  {
    // Implement the pop() function.
    if (st.empty())
      return -1;

    int curr = st.top();
    st.pop();

    if (curr > mini)
    {
      return curr;
    }
    else
    {
      int prevMn = mini;
      mini = 2 * mini - curr;
      return prevMn;
    }
  }

  int top()
  {
    // Implement the top() function.
    if (st.empty())
      return -1;

    int curr = st.top();
    if (curr < mini)
      return mini;
    else
      return curr;
  }

  bool isEmpty()
  {
    // Implement the isEmpty() function.
    return st.empty();
  }

  int getMin()
  {
    // Implement the getMin() function.
    if (st.empty())
      return -1;
    return mini;
  }
};
