#include "bits/stdc++.h"
using namespace std;

int getBridges(vector<vector<int>> &graph, vector<int> &disc, vector<int> &low_val, vector<bool> &visited, vector<vector<int>> &bridges, int u)
{
  static int i = 1, calls_from_root = 0;
  disc[u] = i++;
  visited[u] = 1;
  int min_val = disc[u];
  for (int v : graph[u])
  {
    if (disc[v] != disc[u] - 1)
      min_val = min(min_val, disc[v]);
    if (!visited[v])
    {
      low_val[v] = getBridges(graph, disc, low_val, visited, bridges, v);
      low_val[u] = min(low_val[u], low_val[v]);
      // cout << u << "  " << v << endl;
      // cout << disc[u] << "  " << low_val[v] << endl;
      if (low_val[v] >= disc[u] && disc[u] != 1)
      {
        bridges.push_back({u, v});
      }
    }
  }
  min_val = min(min_val, low_val[u]);
  return min_val;
}

int main()
{
  // vector<vector<int>> graph = {
  //     {1, 2},
  //     {0, 2, 3, 4, 6},
  //     {0, 1},
  //     {1, 5},
  //     {1, 5},
  //     {3, 4},
  //     {1}};
  vector<vector<int>> graph = {
      {1, 2},
      {0, 2},
      {0, 1, 3},
      {2, 4},
      {3}};
  int n = graph.size();
  vector<int> disc(n, INT_MAX), low_val(n, INT_MAX);
  vector<bool> visited(n, 0);
  vector<vector<int>> bridges;
  int start = 0;
  cout << "Bridges are :: ";
  low_val[start] = getBridges(graph, disc, low_val, visited, bridges, start);
  for (auto a : bridges)
  {
    cout << a[0] << "->" << a[1] << "  ";
  }
  return 0;
}
