#include "bits/stdc++.h"
using namespace std;
struct Node
{
  struct Node *left;
  int data;
  struct Node *right;
};
class Tree
{
  Node *root;

public:
  void create();
  void preorder();
  void inorder();
  void postorder();
  void levelorder();
};

void Tree::inorder()
{
  Node *temp = root;
  stack<Node *> st;
  while (!st.empty() || root != NULL)
  {
    if (root)
    {
      st.push(root);
      root = root->left;
    }
    else
    {
      root = st.top();
      st.pop();
      cout << root->data << " ";
      root = root->right;
    }
  }
  root = temp;
}

void Tree::preorder()
{
  Node *temp = root;
  stack<Node *> st;
  st.push(temp);
  while (!st.empty())
  {
    temp = st.top();
    st.pop();
    cout << temp->data << " ";
    if (temp->right)
      st.push(temp->right);
    if (temp->left)
      st.push(temp->left);
  }
}

void Tree::postorder()
{
  Node *temp = root;
  stack<Node *> s, out;
  s.push(temp);
  while (!s.empty())
  {
    temp = s.top();
    s.pop();
    out.push(temp);
    if (temp->left)
      s.push(temp->left);
    if (temp->right)
      s.push(temp->right);
  }
  while (!out.empty())
  {
    temp = out.top();
    out.pop();
    cout << temp->data << " ";
  }
}

void Tree::create()
{
  Node *p, *t;
  int x;
  queue<Node *> q;
  cout << "Enter Root Value :: ";
  cin >> x;
  root = new Node;
  root->data = x;
  root->left = root->right = NULL;
  q.emplace(root);
  while (!q.empty())
  {
    p = q.front();
    q.pop();
    cout << "Enter Left Child of " << p->data << " :: ";
    cin >> x;
    if (x != -1)
    {
      t = new Node;
      t->data = x;
      t->left = t->right = NULL;
      p->left = t;
      q.emplace(t);
    }
    cout << "Enter Right Child of " << p->data << " :: ";
    cin >> x;
    if (x != -1)
    {
      t = new Node;
      t->data = x;
      t->left = t->right = NULL;
      p->right = t;
      q.emplace(t);
    }
  }
}

int main()
{
  Tree t;
  t.create();
  cout << "Inorder :: ";
  t.inorder();
  cout << endl
       << "Preorder :: ";
  t.preorder();
  cout << endl
       << "Postorder :: ";
  t.postorder();
  return 0;
}
