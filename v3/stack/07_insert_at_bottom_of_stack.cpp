#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &myStack, int x)
{
  // base case
  if (myStack.empty())
  {
    myStack.push(x);
    return;
  }

  int num = myStack.top();
  myStack.pop();

  // recursve calls
  solve(myStack, x);

  myStack.push(num);
}

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
  // Write your code here.
  solve(myStack, x);
  return myStack;
}

int main()
{
  stack<int> st;

  st.push(7);
  st.push(11);
  st.push(19);
  st.push(27);

  pushAtBottom(st, 3);

  return 0;
}