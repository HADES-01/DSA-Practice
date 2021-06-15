#include "bits/stdc++.h"
using namespace std;

void Heapify(vector<int> &a, int n, int i)
{
  int j = i * 2 + 1;
  if (j < n && j + 1 < n && a[j] < a[j + 1])
    j = j + 1;
  if (j < n && a[i] < a[j])
  {
    swap(a[i], a[j]);
    Heapify(a, n, j);
  }
}

void HeapSort(vector<int> &a, int n)
{
  for (int i = 0; i < n / 2; i++)
  {
    Heapify(a, n, i);
  }
  for (int k = n - 1; k > 0; k--)
  {
    swap(a[0], a[k]);
    Heapify(a, k, 0);
  }
}

int main()
{
  vector<int> A({8, 4, 2, 6, 3, 6, 3, 5});
  int n = A.size();
  HeapSort(A, n);
  for (int a : A)
  {
    cout << a << " ";
  }
  return 0;
}
