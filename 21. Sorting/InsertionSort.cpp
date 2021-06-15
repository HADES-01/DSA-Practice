#include "bits/stdc++.h"
using namespace std;

int main()
{
  vector<int> A({8, 4, 2, 6, 3, 6, 3, 5});
  int n = A.size();
  for (int i = 1; i < n; i++)
  {
    int j = i - 1, x = A[i];
    while (j >= 0 && A[j] > x)
    {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = x;
  }
  for (int a : A)
  {
    cout << a << " ";
  }
  return 0;
}
