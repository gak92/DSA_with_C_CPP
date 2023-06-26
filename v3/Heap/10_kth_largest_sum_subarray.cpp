#include <bits/stdc++.h>

// solution # 2- Using min heap
int getKthLargest(vector<int> &arr, int k)
{
  //	Write your code here.

  priority_queue<int, vector<int>, greater<int>> minheap;
  int n = arr.size();

  for (int i = 0; i < n; i++)
  {
    int sum = 0;
    for (int j = i; j < n; j++)
    {
      sum += arr[j];
      if (minheap.size() < k)
      {
        minheap.push(sum);
      }
      else
      {
        if (minheap.top() < sum)
        {
          minheap.pop();
          minheap.push(sum);
        }
      }
    }
  }

  return minheap.top();

  // solution # 1
  /*
  vector<int> res;
  int n = arr.size();

  for(int i=0; i<n; i++)
  {
    int sum = 0;
    for(int j=i; j<n; j++)
    {
      sum += arr[j];
      res.push_back(sum);
    }
  }

  sort(res.begin(), res.end());
  return res[res.size() - k];
  */
}