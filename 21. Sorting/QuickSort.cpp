#include "bits/stdc++.h"
using namespace std;

int Partition(vector<int> &A, int l, int h)
{
  int pivot = A[l], i = l, j = h;
  do
  {
    do
    {
      i++;
    } while (A[i] <= pivot);
    do
    {
      j--;
    } while (A[j] > pivot);
    if (i < j)
      swap(A[i], A[j]);
  } while (i < j);
  swap(A[l], A[j]);
  return j;
}

void QuickSort(vector<int> &A, int l, int h)
{
  int j;
  if (h > l)
  {
    j = Partition(A, l, h);
    QuickSort(A, l, j);
    QuickSort(A, j + 1, h);
  }
}

int main()
{
  vector<int> A({8, 4, 2, 6, 3, 6, 3, 5});
  int n = A.size();
  QuickSort(A, 0, n);
  for (int a : A)
  {
    cout << a << " ";
  }
  return 0;
}
