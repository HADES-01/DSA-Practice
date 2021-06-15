#include "bits/stdc++.h"
using namespace std;

int lowVal(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &disc, vector<int> &low_val, vector<bool> &recSt, int u)
{
  static int i = 1;
  visited[u] = 1;
  disc[u] = i++;
  int min_val;
  min_val = disc[u];
  recSt[u] = 1;
  for (int a : graph[u])
  {
    if (disc[u] != disc[a] - 1 && recSt[a])
      min_val = min(min_val, disc[a]);
    if (!visited[a])
    {
      low_val[a] = lowVal(graph, visited, disc, low_val, recSt, a);
      low_val[u] = min(low_val[u], low_val[a]);
    }
  }
  recSt[u] = 0;
  return min(min_val, low_val[u]);
}

void tarjansUtil(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &disc, vector<int> &low_val, stack<int> &st, int u)
{
  st.push(u);
  visited[u] = 1;
  for (int a : graph[u])
  {
    if (!visited[a])
      tarjansUtil(graph, visited, disc, low_val, st, a);
  }
  if (disc[u] == low_val[u])
  {
    int a = st.top();
    while (a != u)
    {
      cout << a << " ";
      st.pop();
      a = st.top();
    }
    cout << a << " ";
    st.pop();
    cout << endl;
  }
}

void tarjans(vector<vector<int>> &graph)
{
  int start = 0, n = graph.size();
  vector<bool> visited(n, 0), recSt(n, 0);
  vector<int> disc(n, 0);
  vector<int> low_val(n, INT_MAX);
  stack<int> st;
  low_val[start] = lowVal(graph, visited, disc, low_val, recSt, start);
  visited = vector<bool>(n, 0);
  tarjansUtil(graph, visited, disc, low_val, st, start);
}

int main()
{
  vector<vector<int>> graph = {
      {1},
      {2},
      {0, 3},
      {4},
      {}};
  tarjans(graph);
  return 0;
}
