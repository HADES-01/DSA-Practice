#include "bits/stdc++.h"
using namespace std;

bool DFSRec(vector<vector<int>> &graph, vector<bool> visited, int u, int parent)
{
  visited[u] = 1;
  for (int v : graph[u])
  {
    if (!visited[v])
    {
      if (DFSRec(graph, visited, v, u))
        return true;
    }
    else if (v != parent)
    {
      return true;
    }
  }
  return false;
}

bool cycle(vector<vector<int>> &graph, int v)
{
  vector<bool> visited(v, 0);
  for (int i = 0; i < v; i++)
  {
    if (!visited[i])
    {
      if (DFSRec(graph, visited, i, -1))
        return true;
    }
  }
  return false;
}

bool cycleKahns(vector<vector<int>> graph, int v)
{
  vector<int> indegree(v, 0);
  for (auto u : graph)
  {
    for (auto v : u)
    {
      indegree[v]++;
    }
  }
  queue<int> q;
  for (int i = 0; i < v; i++)
  {
    if (!indegree[i])
      q.push(i);
  }
  int count = 0;
  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    for (auto a : graph[u])
    {
      indegree[u]--;
      if (!indegree[u])
      {
        q.push(u);
      }
    }
  }
  return (count != v);
}

int main()
{
  vector<vector<int>> graph = {{1}, {0, 2}, {1, 4}, {2, 4}, {2, 3}, {3}};
  cout << cycle(graph, graph.size());
  return 0;
}
