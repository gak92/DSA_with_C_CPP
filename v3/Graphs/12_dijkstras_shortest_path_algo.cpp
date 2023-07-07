#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
  // create adjacency list
  unordered_map<int, list<pair<int, int>>> adj;
  for (int i = 0; i < edges; i++)
  {
    int u = vec[i][0];
    int v = vec[i][1];
    int w = vec[i][2];

    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }

  // create distance array and initialize to infinity
  vector<int> distance(vertices);
  for (int vertex = 0; vertex < vertices; vertex++)
  {
    distance[vertex] = INT_MAX;
  }

  // source to source distance is zero
  distance[source] = 0;
  // create set of pair (distance, node)
  set<pair<int, int>> st;
  st.insert(make_pair(0, source));

  while (!st.empty())
  {
    // fetch top record
    auto top = *(st.begin());
    int nodeDistance = top.first;
    int topNode = top.second;

    // remove top record
    st.erase(st.begin());

    for (auto nebor : adj[topNode])
    {
      if (nodeDistance + nebor.second < distance[nebor.first])
      {
        auto record = st.find(make_pair(distance[nebor.first], nebor.first));
        // if found then remove it
        if (record != st.end())
        {
          st.erase(record);
        }

        // update distance
        distance[nebor.first] = nodeDistance + nebor.second;

        // insert into set
        st.insert(make_pair(distance[nebor.first], nebor.first));
      }
    }
  }

  return distance;
}

int main()
{

  return 0;
}
