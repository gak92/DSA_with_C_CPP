#include <bits/stdc++.h>
using namespace std;

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
  // create adjacent list
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++)
  {
    int u = edges[i].first - 1;
    int v = edges[i].second - 1;

    adj[u].push_back(v);
  }

  // find all indegrees
  vector<int> indegrees(n);
  for (auto i : adj)
  {
    for (auto j : i.second)
    {
      indegrees[j]++;
    }
  }

  // push all nodes in q which has 0 indegrees
  queue<int> q;
  for (int node = 0; node < n; node++)
  {
    if (indegrees[node] == 0)
    {
      q.push(node);
    }
  }

  // do BFS
  int count = 0;
  while (!q.empty())
  {
    int frontNode = q.front();
    q.pop();

    count++;

    // update nebor indegrees
    for (auto nebor : adj[frontNode])
    {
      indegrees[nebor]--;
      if (indegrees[nebor] == 0)
      {
        q.push(nebor);
      }
    }
  }

  if (count == n)
    return false;
  else
    return true;
}

int main()
{

  return 0;
}