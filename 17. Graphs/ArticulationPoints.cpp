#include "bits/stdc++.h"
using namespace std;

int checkArti(vector<vector<int>> &graph, vector<int> &disc, vector<int> &low_val, vector<bool> &visited, vector<bool> &isArticulate, int u)
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
      if (disc[u] == 1)
      {
        calls_from_root++;
        if (calls_from_root > 1)
          isArticulate[u] = 1;
      }
      low_val[v] = checkArti(graph, disc, low_val, visited, isArticulate, v);
      low_val[u] = min(low_val[u], low_val[v]);
      if (low_val[v] >= disc[u] && disc[u] != 1)
      {
        isArticulate[u] = 1;
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
  vector<bool> visited(n, 0), isArticulate(n, 0);
  int start = 0;
  cout << "Articulation Points are :: ";
  low_val[start] = checkArti(graph, disc, low_val, visited, isArticulate, start);
  for (int i = 0; i < n; i++)
  {
    if (isArticulate[i])
      cout << i << " ";
  }
  // cout << "\nLow_val :: ";
  // for (auto a : low_val)
  //   cout << a << " ";
  // cout << "\ndisc :: ";
  // for (auto a : disc)
  //   cout << a << " ";
  return 0;
}
