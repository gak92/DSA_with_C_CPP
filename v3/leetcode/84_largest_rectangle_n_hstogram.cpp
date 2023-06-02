#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> arr, int n)
{
  vector<int> res(n);
  stack<int> st;
  st.push(-1);

  for (int j = n - 1; j >= 0; j--)
  {
    int curr = arr[j];
    while (st.top() != -1 && arr[st.top()] >= curr)
    {
      st.pop();
    }
    res[j] = st.top();
    st.push(j);
  }
  return res;
}

vector<int> prevSmallerElement(vector<int> arr, int n)
{
  vector<int> res(n);
  stack<int> st;
  st.push(-1);

  for (int j = 0; j < n; j++)
  {
    int curr = arr[j];
    while (st.top() != -1 && arr[st.top()] >= curr)
    {
      st.pop();
    }
    res[j] = st.top();
    st.push(j);
  }
  return res;
}

int largestRectangleArea(vector<int> &heights)
{
  int n = heights.size();

  vector<int> next;
  next = nextSmallerElement(heights, n);

  vector<int> prev;
  prev = prevSmallerElement(heights, n);

  int area = INT_MIN;
  for (int j = 0; j < n; j++)
  {
    int l = heights[j];
    if (next[j] == -1)
    {
      next[j] = n;
    }
    int b = next[j] - prev[j] - 1;

    int newArea = l * b;
    area = max(area, newArea);
  }

  return area;
}

int main()
{
  vector<int> heights{2, 1, 5, 6, 2, 3};

  cout << "Largest rectangle area: " << largestRectangleArea(heights) << endl;
  return 0;
}