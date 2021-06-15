#include "bits/stdc++.h"
using namespace std;

void KosarajuUtil(vector<vector<int>> &graph, vector<bool> &visited, stack<int> &st, int u)
{
  visited[u] = 1;
  for (int v : graph[u])
  {
    if (!visited[v])
    {
      KosarajuUtil(graph, visited, st, v);
    }
  }
  st.push(u);
}

void DFS(vector<vector<int>> &graph, vector<bool> &visited, int u)
{
  cout << u << " ";
  visited[u] = 1;
  for (int v : graph[u])
  {
    if (!visited[v])
    {
      DFS(graph, visited, v);
    }
  }
}
vector<vector<int>> reverseEdges(vector<vector<int>> &graph)
{
  int n = graph.size();
  vector<vector<int>> newGraph(n);
  for (int i = 0; i < n; i++)
  {
    for (int j : graph[i])
    {
      newGraph[j].push_back(i);
    }
  }
  return newGraph;
}
void Kosaraju(vector<vector<int>> &graph, int v)
{
  vector<bool> visited(v, 0);
  stack<int> st;
  for (int i = 0; i < v; i++)
  {
    if (!visited[i])
    {
      KosarajuUtil(graph, visited, st, i);
    }
  }
  visited = vector<bool>(v, 0);
  graph = reverseEdges(graph);
  while (!st.empty())
  {
    int u = st.top();
    st.pop();
    if (!visited[u])
    {
      DFS(graph, visited, u);
      cout << "\n";
    }
  }
}

int main()
{
  vector<vector<int>> graph = {
      {1},
      {2},
      {0,3},
      {4},
      {}};
  Kosaraju(graph, graph.size());
  return 0;
}
