#include <bits/stdc++.h>
using namespace std;

void topSort(unordered_map<int, list<int>> &adj, vector<bool> &visited,
             stack<int> &st, int node)
{
  visited[node] = 1;

  for (auto nebor : adj[node])
  {
    if (!visited[nebor])
    {
      topSort(adj, visited, st, nebor);
    }
  }

  st.push(node);
}

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

  // call dfs if node not visited
  vector<bool> visited(v);
  stack<int> st;

  for (int node = 0; node < v; node++)
  {
    if (!visited[node])
    {
      topSort(adj, visited, st, node);
    }
  }

  vector<int> res;
  while (!st.empty())
  {
    res.push_back(st.top());
    st.pop();
  }

  return res;
}

int main()
{

  return 0;
}