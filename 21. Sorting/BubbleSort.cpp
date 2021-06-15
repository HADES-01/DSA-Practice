#include "bits/stdc++.h"
using namespace std;

int main()
{
  vector<int> A({8, 4, 2, 6, 3, 6, 3, 5});
  int n = A.size();
  bool isSorted = 1;
  for (int i = 0; i < n - 1; i++)
  {
    isSorted = 1;
    for (int j = 0; j < n - 1 - i; j++)
    {
      if (A[j] > A[j + 1])
      {
        swap(A[j], A[j + 1]);
        isSorted = 0;
      }
    }
    if (isSorted)
      break;
  }
  for (int el : A)
  {
    cout << el << " ";
  }
  return 0;
}
