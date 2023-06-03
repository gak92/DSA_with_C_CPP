//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
private:
  vector<int> nextSmallerElements(int *arr, int n)
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

  vector<int> prevSmallerElements(int *arr, int n)
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

  int largestRectangleArea(int *heights, int n)
  {
    vector<int> next(n);
    next = nextSmallerElements(heights, n);

    vector<int> prev(n);
    prev = prevSmallerElements(heights, n);

    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
      int l = heights[i];
      if (next[i] == -1)
        next[i] = n;
      int b = next[i] - prev[i] - 1;
      area = max(area, l * b);
    }
    return area;
  }

public:
  int maxArea(int M[MAX][MAX], int n, int m)
  {
    // compute area for the first row
    int area = largestRectangleArea(M[0], m);

    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (M[i][j] != 0)
          M[i][j] = M[i][j] + M[i - 1][j];
        else
          M[i][j] = 0;
      }
      area = max(area, largestRectangleArea(M[i], m));
    }

    return area;
  }
};

//{ Driver Code Starts.
int main()
{
  int T;
  cin >> T;

  int M[MAX][MAX];

  while (T--)
  {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cin >> M[i][j];
      }
    }
    Solution obj;
    cout << obj.maxArea(M, n, m) << endl;
  }
}

// } Driver Code Ends