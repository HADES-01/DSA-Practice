#include "bits/stdc++.h"
using namespace std;

void BFS(vector<vector<int>> G, int i, int n)
{
  bool visited[n] = {0};
  queue<int> q;
  cout << i << " ";
  visited[i] = 1;
  q.push(i);
  while (!q.empty())
  {
    i = q.front();
    q.pop();
    for (int v = 1; v < n; v++)
    {
      if (G[i][v] && !visited[v])
      {
        cout << v << " ";
        visited[v] = 1;
        q.push(v);
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
  BFS(G, 1, 7);
  return 0;
}
