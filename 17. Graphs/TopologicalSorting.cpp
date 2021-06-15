#include "bits/stdc++.h"
using namespace std;

//Kahn's algorithm based on BFS
void topologicalSort(vector<vector<int>> graph, int n)
{
  vector<int> indegree(n, 0);
  for (auto u : graph)
  {
    for (auto v : u)
    {
      indegree[v]++;
    }
  }
  queue<int> q;
  for (int i = 0; i < n; i++)
  {
    if (!indegree[i])
      q.push(i);
  }
  while (!q.empty())
  {
    int u = q.front();
    cout << u << " ";
    q.pop();
    for (auto v : graph[u])
    {
      indegree[v]--;
      if (!indegree[v])
        q.push(v);
    }
  }
}

//DFS based solution
void DFSutil(vector<vector<int>> &graph, stack<int> &st, vector<bool> &visited, int u)
{
  visited[u] = 1;
  for (int v : graph[u])
  {
    if (!visited[v])
      DFSutil(graph, st, visited, v);
  }
  st.push(u);
}

void topologicalSortDFS(vector<vector<int>> &graph, int v)
{
  vector<bool> visited(v, 0);
  stack<int> st;
  for (int i = 0; i < v; i++)
  {
    if (!visited[i])
    {
      DFSutil(graph, st, visited, i);
    }
  }
  while (!st.empty())
  {
    cout << st.top() << " ";
    st.pop();
  }
}

int main()
{
  vector<vector<int>> graph = {{2, 3}, {3, 4}, {3}, {}, {}};
  topologicalSortDFS(graph, graph.size());
  return 0;
}
