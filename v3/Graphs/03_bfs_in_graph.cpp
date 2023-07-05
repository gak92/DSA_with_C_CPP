#include <bits/stdc++.h> 
using namespace std;

void createAdjacencyList(vector<pair<int, int>> &edges, unordered_map<int, set<int>> &adjList)
{
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfsSearch(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited,
                vector<int> &res, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        res.push_back(frontNode);

        for(auto nbr:adjList[frontNode])
        {
            if(!visited[nbr])
            {
                q.push(nbr);
                visited[nbr] = 1;
            }
        }
    }

}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<int> res;
    unordered_map<int, set<int>> adjList;
    unordered_map<int, bool> visited;

    // create adjacency list
    createAdjacencyList(edges, adjList);

    // traverse all components of the Graph
    for(int i=0; i<vertex; i++)
    {
        if(!visited[i])
        {
            bfsSearch(adjList, visited, res, i);
        }
    }

    return res;
}

int main()
{


  return 0;
}