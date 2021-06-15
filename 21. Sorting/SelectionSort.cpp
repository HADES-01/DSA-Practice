#include "bits/stdc++.h"
using namespace std;

int main()
{
  vector<int> A({8, 4, 2, 6, 3, 6, 3, 5});
  int n = A.size();
  int j, k;
  for (int i = 0; i < n - 1; i++)
  {
    j = k = i;
    while (j < n)
    {
      if (A[j] < A[k])
        k = j;
      j++;
    }
    swap(A[i], A[k]);
  }
  for (int a : A)
  {
    cout << a << " ";
  }
  return 0;
}
