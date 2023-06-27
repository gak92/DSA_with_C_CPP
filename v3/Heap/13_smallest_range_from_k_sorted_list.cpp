#include <bits/stdc++.h>

class node
{
public:
  int data;
  int row;
  int col;

  node(int data, int row, int col)
  {
    this->data = data;
    this->row = row;
    this->col = col;
  }
};

class compare
{
public:
  bool operator()(node *a, node *b)
  {
    return a->data > b->data;
  }
};

int kSorted(vector<vector<int>> &a, int k, int n)
{
  // Write your code here.
  int mini = INT_MAX;
  int maxi = INT_MIN;
  priority_queue<node *, vector<node *>, compare> minheap;

  for (int i = 0; i < k; i++)
  {
    node *temp = new node(a[i][0], i, 0);
    minheap.push(temp);
    mini = min(mini, temp->data);
    maxi = max(maxi, temp->data);
  }

  int start = mini;
  int end = maxi;

  while (!minheap.empty())
  {
    node *temp = minheap.top();
    minheap.pop();

    mini = temp->data;
    if (maxi - mini < end - start)
    {
      start = mini;
      end = maxi;
    }

    int row = temp->row;
    int nextCol = temp->col + 1;
    if (nextCol < n)
    {
      maxi = max(maxi, a[row][nextCol]);
      node *newNode = new node(a[row][nextCol], row, nextCol);
      minheap.push(newNode);
    }
    else
    {
      break;
    }
  }

  return (end - start + 1);
}
