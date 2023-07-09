/*
  Count Strongly connected Components
*/

#include <bits/stdc++.h>
using namespace std;
void dfs(int node, unordered_map<int, list<int>> &adj,
         unordered_map<int, bool> &visited, stack<int> &st)
{
  visited[node] = true;
  for (auto nebor : adj[node])
  {
    if (!visited[nebor])
    {
      dfs(nebor, adj, visited, st);
    }
  }
  st.push(node);
}

void revDFS(int node, unordered_map<int, list<int>> &transpose,
            unordered_map<int, bool> &visited)
{
  visited[node] = true;

  for (auto nebor : transpose[node])
  {
    if (!visited[nebor])
      revDFS(nebor, transpose, visited);
  }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
  // create adjacency list
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++)
  {
    int u = edges[i][0];
    int v = edges[i][1];
    adj[u].push_back(v);
  }

  // 1- topological sorting
  unordered_map<int, bool> visited;
  stack<int> st;
  for (int node = 0; node < v; node++)
  {
    if (!visited[node])
    {
      dfs(node, adj, visited, st);
    }
  }

  // 2- create transpose of a graph
  unordered_map<int, list<int>> transpose;
  for (int node = 0; node < v; node++)
  {
    visited[node] = false;
    for (auto nebor : adj[node])
    {
      transpose[nebor].push_back(node);
    }
  }

  // 3- call dfs using above ordering
  int count = 0;
  while (!st.empty())
  {
    int topNode = st.top();
    st.pop();

    if (!visited[topNode])
    {
      count++;
      revDFS(topNode, transpose, visited);
    }
  }

  return count;
}

int main()
{

  return 0;
}