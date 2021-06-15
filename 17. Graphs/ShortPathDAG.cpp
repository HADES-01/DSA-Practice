#include "bits/stdc++.h"
using namespace std;

void shortPath(vector<vector<vector<int>>> graph, int n, int src)
{
  queue<int> q;
  vector<bool> visited(n, 0);
  vector<int> dist(n, INT_MAX);
  q.push(src);
  dist[src] = 0;
  visited[src] = 1;
  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    for (auto v : graph[u])
    {
      if (dist[u] + v[1] < dist[v[0]])
      {
        dist[v[0]] = dist[u] + v[1];
      }
      if (!visited[v[0]])
      {
        visited[v[0]] = 1;
        q.push(v[0]);
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    cout << i << " " << dist[i] << endl;
  }
}

int main()
{
  vector<vector<vector<int>>> graph = {{{1, 2}, {4, 1}}, {{2, 3}}, {{3, 6}}, {}, {{2, 2}, {5, 4}}, {{3, 1}}};
  int start = 0;
  shortPath(graph, graph.size(), start);
  return 0;
}
