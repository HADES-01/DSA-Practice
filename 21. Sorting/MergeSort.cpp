#include "bits/stdc++.h"
using namespace std;

void merge(vector<int> &a, int l, int h)
{
  int mid = (l + h) / 2;
  int i = l, j = mid + 1, k = l;
  vector<int> b(h + 1);
  while (i <= mid && j <= h)
  {
    if (a[i] < a[j])
    {
      b[k++] = a[i++];
    }
    else
    {
      b[k++] = a[j++];
    }
  }
  while (i <= mid)
    b[k++] = a[i++];
  while (j <= h)
    b[k++] = a[j++];
  for (int i = l; i <= h; i++)
  {
    a[i] = b[i];
  }
}

void mergeIterative(vector<int> &a, int n)
{
  int i;
  for (i = 2; i <= n; i *= 2)
  {
    for (int j = 0; j + i - 1 < n; j += i)
    {
      int l = j, h = i + j - 1;
      merge(a, l, h);
    }
  }
  if (i / 2 < n)
  {
    merge(a, 0, n - 1);
  }
}

void mergeRecursive(vector<int> &a, int l, int h)
{
  if (l < h)
  {
    int mid = (l + h) / 2;
    mergeRecursive(a, l, mid);
    mergeRecursive(a, mid + 1, h);
    merge(a, l, h);
  }
}

int main()
{
  vector<int> A({8, 4, 2, 6, 3, 6, 3, 5});
  int n = A.size();
  mergeRecursive(A, 0, n - 1);
  for (int a : A)
  {
    cout << a << " ";
  }
  return 0;
}
