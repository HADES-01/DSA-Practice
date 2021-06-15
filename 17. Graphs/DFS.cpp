#include "bits/stdc++.h"
using namespace std;

void DFS(vector<vector<int>> G, int i, int n)
{
  static bool visited[7] = {0};
  if (!visited[i])
  {
    cout << i << " ";
    visited[i] = 1;
    for (int v = 1; v < n; v++)
    {
      if (G[i][v] && !visited[v])
      {
        DFS(G, v, n);
      }
    }
  }
}

int main()
{
  vector<vector<int>> G = {{0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 1, 1, 0, 0, 0},
                           {0, 1, 0, 0, 1, 0, 0},
                           {0, 1, 0, 0, 1, 0, 0},
                           {0, 0, 1, 1, 0, 1, 1},
                           {0, 0, 0, 0, 1, 0, 0},
                           {0, 0, 0, 0, 1, 0, 0}};
  DFS(G, 1, 7);
  return 0;
}