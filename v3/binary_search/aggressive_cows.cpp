#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> stalls, int k, int mid)
{
  int cowCount = 1;
  int lastPos = stalls[0];
  int n = stalls.size();

  for (int i = 0; i < n; i++)
  {
    if (stalls[i] - lastPos >= mid)
    {
      cowCount++;
      if (cowCount == k)
      {
        return true;
      }
      lastPos = stalls[i];
    }
  }

  return false;
}

int aggressive_cow(vector<int> stalls, int k)
{
  sort(stalls.begin(), stalls.end());
  int start = 0;
  int maxi = -1;
  int n = stalls.size();
  for (int i = 0; i < n; i++)
  {
    maxi = max(maxi, stalls[i]);
  }
  int end = maxi;
  int res = -1;
  int mid = start + (end - start) / 2;

  while (start <= end)
  {
    if (isPossible(stalls, k, mid))
    {
      res = mid;
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
    mid = start + (end - start) / 2;
  }
  return res;
}

int main()
{
  // vector<int> stalls = {1, 2, 3}; // Stall position
  // int k = 2;

  // vector<int> stalls = {0, 3, 4, 7, 10, 9};
  // int k = 4; // Number of cows

  vector<int> stalls = {4, 2, 1, 3, 6};
  int k = 2;

  cout << "Largest minimum distance: " << aggressive_cow(stalls, k) << endl;
  return 0;
}