#include "bits/stdc++.h"
using namespace std;

struct Node
{
  Node *left;
  int data;
  Node *right;
  Node(int x)
  {
    left = right = NULL;
    data = x;
  }
}

void
verticalOrder(Node *root)
{
  if (!root)
    return;
  map<int, vector<int>> horiz;
  //queue to store the node as well as its horizontal distance
  queue<pair<Node *, int>> q;
  Node *temp = root;
  int hd = 0;
  q.push(make_pair(temp, hd));
  while (!q.empty())
  {
    pair<Node *, int> front = q.front();
    q.pop();
    temp = front.first;
    hd = front.second;
    horiz[hd].push_back(temp->data);
    if (!temp->left)
      q.push(make_pair(temp->left, hd - 1));
    if (!temp->right)
      q.push(make_pair(temp->right, hd + 1));
  }
  for (auto a : horiz)
  {
    for (int el : a.second)
    {
      cout << el << " ";
    }
  }
}

int main()
{
  Node *root = new Node(5);
  return 0;
}
