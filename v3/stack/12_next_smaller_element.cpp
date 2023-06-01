/*
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
  // Write your code here.
  vector<int> res(n);
  stack<int> st;
  st.push(-1);

  for (int i = n - 1; i >= 0; i--)
  {
    int curr = arr[i];
    while (st.top() >= curr)
    {
      st.pop();
    }
    res[i] = st.top();
    st.push(curr);
  }

  return res;
}

int main()
{

  return 0;
}