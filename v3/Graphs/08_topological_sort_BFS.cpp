#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
  // Write your code here
  // create adjacency list
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < e; i++)
  {
    int u = edges[i][0];
    int v = edges[i][1];

    adj[u].push_back(v);
  }

  // find all indegrees
  vector<int> indegrees(v);
  for (auto i : adj)
  {
    for (auto j : i.second)
    {
      indegrees[j]++;
    }
  }

  // push 0 indegree
  queue<int> q;
  for (int i = 0; i < v; i++)
  {
    if (indegrees[i] == 0)
      q.push(i);
  }

  // Do BFS
  vector<int> res;
  while (!q.empty())
  {
    int frontNode = q.front();
    q.pop();

    res.push_back(frontNode);

    // neighbor indegree update
    for (auto nebor : adj[frontNode])
    {
      indegrees[nebor]--;
      if (indegrees[nebor] == 0)
      {
        q.push(nebor);
      }
    }
  }

  return res;
}

int main()
{

  return 0;
}