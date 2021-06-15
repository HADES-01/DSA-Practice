#include "bits/stdc++.h"
using namespace std;

int getsum(vector<int> &bItree, int i)
{
  i += 1;
  int sum = 0;
  while (i > 0)
  {
    sum += bItree[i];
    i -= (i & (-i));
  }
  return sum;
}

void update(vector<int> &bItree, vector<int> &arr, int diff, int idx)
{
  int n = arr.size();
  arr[idx] += diff;
  idx += 1;
  while (idx <= n)
  {
    bItree[idx] += diff;
    idx += (idx & (-idx));
  }
}

void construct(vector<int> &arr, vector<int> &bItree)
{
  for (int i = 0; i < arr.size(); i++)
  {
    update(bItree, arr, arr[i], i);
  }
}

int main()
{
  vector<int> arr({10, 20, 30, 40, 50, 60});
  vector<int> bItree(arr.size() + 1, 0);
  construct(arr, bItree);
  update(bItree, arr, 30, 1);
  cout << getsum(bItree, 3);
  return 0;
}
