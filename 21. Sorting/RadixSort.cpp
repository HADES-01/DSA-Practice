#include "bits/stdc++.h"
using namespace std;

int digits(int a)
{
  int ctr = -1;
  while (a)
  {
    a /= 10;
    ctr++;
  }
  return ctr;
}

void radixSort(vector<int> &a, int n)
{
  int nd = digits(*max_element(a.begin(), a.end()));
  vector<queue<int>> rd(10);
  double power = pow(10, nd);
  for (int p = 1; p <= power; p *= 10)
  {
    for (int j = 0; j < n; j++)
    {
      rd[(a[j] / p) % 10].push(a[j]);
    }
    int i = 0, j = 0;
    while (j < 10)
    {
      if (!rd[j].empty())
      {
        a[i++] = rd[j].front();
        rd[j].pop();
      }
      else
      {
        j++;
      }
    }
  }
}

int main()
{
  vector<int> A({88, 44, 22, 645, 345, 163, 3, 5});
  int n = A.size();
  radixSort(A, n);
  for (int a : A)
  {
    cout << a << " ";
  }
  return 0;
}
