#include "bits/stdc++.h"
#define I INT_MAX
using namespace std;

void PrimsMST(vector<vector<int>> cost, int n)
{
  vector<int> near(n, I);
  int t[2][n - 2];
  int min = I, u, v;
  for (int i = 1; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      if (min > cost[i][j])
      {
        min = cost[i][j];
        u = i;
        v = j;
      }
    }
  }
  t[0][0] = u;
  t[1][0] = v;
  near[u] = near[v] = 0;
  for (int i = 1; i < n; i++)
  {
    if (near[i])
    {
      if (cost[i][u] > cost[i][v])
      {
        near[i] = v;
      }
      else
      {
        near[i] = u;
      }
    }
  }
  int k = 0;
  cout << endl;
  for (int i = 1; i < n - 2; i++)
  {
    min = I;
    for (int j = 1; j < n; j++)
    {
      if (near[j])
      {
        if (cost[j][near[j]] < min)
        {
          min = cost[j][near[j]];
          k = j;
        }
      }
    }
    t[0][i] = k;
    t[1][i] = near[k];
    near[k] = 0;
    for (int j = 1; j < n; j++)
    {
      if (near[j] && cost[j][near[j]] > cost[j][k])
      {
        near[j] = k;
      }
    }
  }
  int sum = 0;
  for (int i = 0; i < n - 2; i++)
  {
    sum += cost[t[0][i]][t[1][i]];
    cout << "(" << t[0][i] << "," << t[1][i] << ") costs " << cost[t[0][i]][t[1][i]] << "\n";
  }
  cout << "\nMST sum :: " << sum;
}

int main()
{
  vector<vector<int>> cost =
      {{I, I, I, I, I, I, I, I},
       {I, I, 25, I, I, I, 5, I},
       {I, 25, I, 12, I, I, I, 10},
       {I, I, 12, I, 8, I, I, I},
       {I, I, I, 8, I, 16, I, 14},
       {I, I, I, I, 16, I, 20, 18},
       {I, 5, I, I, I, 20, I, I},
       {I, I, 10, I, 14, 18, I, I}};
  PrimsMST(cost, 8);
  return 0;
}
