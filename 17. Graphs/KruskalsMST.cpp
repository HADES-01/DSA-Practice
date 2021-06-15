#include "bits/stdc++.h"
#define I INT_MAX
using namespace std;

void join(vector<int> &s, int i, int j)
{
  if (s[i] < s[j])
  {
    s[i] += s[j];
    s[j] = i;
  }
  else
  {
    s[j] += s[i];
    s[i] = j;
  }
}

int find(vector<int> &s, int key)
{
  int a = key, y;
  while (s[a] > 0)
  {
    a = s[a];
  }
  while (key != a)
  {
    y = s[key];
    s[key] = a;
    key = y;
  }
  return a;
}

void kruskalsMST(vector<vector<int>> edges, int n, int v)
{
  int included[n] = {0};
  vector<int> set(n, -1);
  int t[2][v - 1];
  int k = 0;
  while (k < v - 1)
  {
    int min = I, j = 0;
    for (int i = 0; i < n; i++)
    {
      if (!included[i] && min > edges[i][2])
      {
        min = edges[i][2];
        j = i;
      }
    }
    if (find(set, edges[j][0]) != find(set, edges[j][1]))
    {
      t[0][k] = edges[j][0];
      t[1][k] = edges[j][1];
      join(set, find(set, edges[j][0]), find(set, edges[j][1]));
      k++;
    }
    else
      included[j] = 1;
  }
  for (int i = 0; i < v - 1; i++)
  {
    cout << "(" << t[0][i] << "," << t[1][i] << ") \n";
  }
}

int main()
{
  vector<vector<int>> edges = {
      {1, 2, 28},
      {1, 6, 10},
      {2, 3, 16},
      {2, 7, 14},
      {3, 4, 12},
      {4, 5, 22},
      {4, 7, 18},
      {5, 6, 25},
      {5, 7, 24}};
  kruskalsMST(edges, 9, 7);
  return 0;
}
