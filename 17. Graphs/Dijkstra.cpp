#include "bits/stdc++.h"
#define I INT_MAX
using namespace std;

int min_vertex(vector<int> &dist, vector<int> &visited)
{
  int min = I, min_index;
  for (int i = 0; i < dist.size(); i++)
  {
    if (min >= dist[i] && !visited[i])
    {
      min = dist[i];
      min_index = i;
    }
  }
  return min_index;
}

void dijkstras(vector<vector<int>> &graph, int start, int n)
{
  vector<int> dist(n, I);
  vector<int> visited(n, 0);
  dist[start] = 0;
  for (int i = 0; i < n - 1; i++)
  {
    int min = min_vertex(dist, visited);
    visited[min] = 1;
    for (int j = 0; j < n; j++)
    {
      if (dist[min] != I && !visited[j] && graph[min][j] && (dist[min] + graph[min][j]) < dist[j])
      {
        cout << "here ";
        dist[j] = dist[min] + graph[min][j];
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    cout << i << " " << dist[i] << "\n";
  }
}

int main()
{
  int V = 9;
  vector<vector<int>> graph = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                               {4, 0, 8, 0, 0, 0, 0, 11, 0},
                               {0, 8, 0, 7, 0, 4, 0, 0, 2},
                               {0, 0, 7, 0, 9, 14, 0, 0, 0},
                               {0, 0, 0, 9, 0, 10, 0, 0, 0},
                               {0, 0, 4, 14, 10, 0, 2, 0, 0},
                               {0, 0, 0, 0, 0, 2, 0, 1, 6},
                               {8, 11, 0, 0, 0, 0, 1, 0, 7},
                               {0, 0, 2, 0, 0, 0, 6, 7, 0}};
  dijkstras(graph, 0, V);
  return 0;
}
