#include "bits/stdc++.h"
using namespace std;

void BellmanFord(vector<vector<vector<int>>> &graph, int v, int src)
{
  vector<int> dist(v, INT_MAX);
  dist[src] = 0;
  for (int ctr = 0; ctr < v - 1; ctr++)
  {
    for (int u = 0; u < v; u++)
    {
      for (auto v : graph[u])
      {
        if (dist[v[0]] > dist[u] + v[1])
        {
          dist[v[0]] = dist[u] + v[1];
        }
      }
    }
  }
  for (int i = 0; i < v; i++)
  {
    cout << i << " " << dist[i] << endl;
  }
}

int main()
{
  vector<vector<vector<int>>> graph = {{{1, 2}, {4, 1}}, {{2, 3}}, {{3, 6}}, {}, {{2, 2}, {5, 4}}, {{3, 1}}};
  int start = 0;
  BellmanFord(graph, graph.size(), start);
  return 0;
}
