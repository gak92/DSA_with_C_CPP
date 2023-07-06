#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{

  // create adjacency list
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++)
  {
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // do BFS
  unordered_map<int, bool> visited;
  unordered_map<int, int> parent;
  queue<int> q;

  q.push(s);
  visited[s] = 1;
  parent[s] = -1;

  while (!q.empty())
  {
    int frontNode = q.front();
    q.pop();

    for (auto nebor : adj[frontNode])
    {
      if (!visited[nebor])
      {
        q.push(nebor);
        visited[nebor] = 1;
        parent[nebor] = frontNode;
      }
    }
  }

  // prepare shortest path
  vector<int> res;
  int currNode = t;
  res.push_back(currNode);

  while (currNode != s)
  {
    currNode = parent[currNode];
    res.push_back(currNode);
  }

  reverse(res.begin(), res.end());
  return res;
}

int main()
{

  return 0;
}
