#include "bits/stdc++.h"
using namespace std;

int createSegment(vector<int> &arr, vector<int> &segment, int start, int end, int idx)
{
  if (start == end)
  {
    segment[idx] = arr[start];
    return arr[start];
  }
  int mid = (start + end) / 2;
  segment[idx] = createSegment(arr, segment, start, mid, 2 * idx + 1) + createSegment(arr, segment, mid + 1, end, 2 * idx + 2);
  return segment[idx];
}

int rangeQuery(vector<int> &arr, vector<int> &segment, int l, int r, int start, int end, int idx)
{
  if (l > end || r < start)
    return 0;
  if (l <= start && r >= end)
    return segment[idx];
  int mid = (start + end) / 2;
  return rangeQuery(arr, segment, l, r, start, mid, 2 * idx + 1) + rangeQuery(arr, segment, l, r, mid + 1, end, 2 * idx + 2);
}

void updateSegment(vector<int> &arr, vector<int> &segment, int start, int end, int idx, int uidx, int diff)
{
  if (uidx > end || uidx < start)
    return;
  segment[idx] += diff;
  if (start < end)
  {
    int mid = (start + end) / 2;
    updateSegment(arr, segment, start, mid, 2 * idx + 1, uidx, diff);
    updateSegment(arr, segment, mid + 1, end, 2 * idx + 2, uidx, diff);
  }
}

int main()
{
  vector<int> arr({10, 20, 30, 40, 50});
  int n = arr.size();
  int treeSize = 4 * n;
  vector<int> segment(treeSize, 0);
  segment[0] = createSegment(arr, segment, 0, n - 1, 0);
  updateSegment(arr, segment, 0, n - 1, 0, 2, 40);
  cout << "Sum in range 1 to 4 :: " << rangeQuery(arr, segment, 1, 4, 0, n - 1, 0);
  return 0;
}
