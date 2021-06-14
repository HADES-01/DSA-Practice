#include "bits/stdc++.h"
using namespace std;

void countSort(vector<int> &a, int n)
{
  int max = *max_element(a.begin(), a.end());
  vector<int> b(max + 1, 0);
  for (int i = 0; i < n; i++)
  {
    b[a[i]]++;
  }
  int i = 0, j = 0;
  while (i < n)
  {
    if (b[i] > 0)
    {
      a[j++] = i;
      b[i]--;
    }
    else
    {
      i++;
    }
  }
}

int main()
{
  vector<int> A({8, 4, 2, 6, 3, 6, 3, 5});
  int n = A.size();
  countSort(A, n);
  for (int a : A)
  {
    cout << a << " ";
  }
  return 0;
}
