#include "bits/stdc++.h"
using namespace std;

void shellSort(vector<int> &a, int n)
{
  for (int gap = n / 2; gap >= 1; gap /= 2)
  {
    for (int i = gap; i < n; i++)
    {
      int j = i - gap, temp = a[i];
      while (j >= 0 && a[j] > temp)
      {
        a[j + gap] = a[j];
        j = j - gap;
      }
      a[j + gap] = temp;
    }
  }
}

int main()
{
  vector<int> A({88, 44, 22, 645, 345, 163, 3, 5});
  int n = A.size();
  shellSort(A, n);
  for (int a : A)
  {
    cout << a << " ";
  }
  return 0;
}
