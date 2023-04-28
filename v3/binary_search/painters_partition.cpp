#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> boards, int size, int k, int mid)
{
  int painterCount = 1;
  int boardSum = 0;

  for (int i = 0; i < size; i++)
  {
    if (boardSum + boards[i] <= mid)
    {
      boardSum += boards[i];
    }
    else
    {
      painterCount++;
      if (painterCount > k || boards[i] > mid)
      {
        return false;
      }
      boardSum = boards[i];
    }
  }
  return true;
}

int findLargestMinDistance(vector<int> boards, int size, int k)
{
  int start = 0;
  int sum = 0;
  for (int i = 0; i < size; i++)
  {
    sum += boards[i];
  }
  int end = sum;
  int res = -1;
  int mid = start + (end - start) / 2;

  while (start <= end)
  {
    if (isPossible(boards, size, k, mid))
    {
      res = mid;
      end = mid - 1;
    }
    else
    {
      start = mid + 1;
    }
    mid = start + (end - start) / 2;
  }

  return res;
}

int main()
{
  // vector<int> boards = {5, 5, 5, 5}; // Each board size
  vector<int> boards = {10, 20, 30, 40};
  int size = boards.size(); // Total number of boards

  int k = 2; // Number of painters

  cout << "Painter can board paint minimum: " << findLargestMinDistance(boards, size, k) << endl;
  return 0;
}