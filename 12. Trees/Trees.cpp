#include "bits/stdc++.h"
using namespace std;

struct Node
{
  struct Node *lchild;
  int data;
  struct Node *rchild;
};

class Tree
{
  Node *root;

public:
  void create();
  void preorder(Node *);
  void inorder(Node *);
  void postorder(Node *);
  void levelorder(Node *);
  int height(Node *);
  int height()
  {
    return height(root);
  }
  int count(Node *);
  int count()
  {
    return count(root);
  }
  void display()
  {
    preorder(root);
  }
  void display(int type)
  {
    if (type == 1)
      preorder(root);
    else if (type == 2)
      inorder(root);
    else if (type == 3)
      postorder(root);
    else
      levelorder(root);
  }
};

int Tree::height(Node *root)
{
  int x, y;
  if (root)
  {
    x = height(root->lchild);
    y = height(root->rchild);
    return max(x, y) + 1;
  }
  return 0;
}

int Tree::count(Node *root)
{
  int x, y;
  if (root)
  {
    x = count(root->lchild);
    y = count(root->rchild);
    return x + y + 1;
  }
  return 0;
}

void Tree::levelorder(Node *root)
{
  queue<Node *> q;
  cout << root->data << " ";
  q.push(root);
  while (!q.empty())
  {
    root = q.front();
    q.pop();
    if (root->lchild)
    {
      cout << root->lchild->data << " ";
      q.push(root->lchild);
    }
    if (root->rchild)
    {
      cout << root->rchild->data << " ";
      q.push(root->rchild);
    }
  }
}

void Tree::preorder(Node *root)
{
  if (root)
  {
    cout << root->data << " ";
    preorder(root->lchild);
    preorder(root->rchild);
  }
}
void Tree::inorder(Node *root)
{
  if (root)
  {
    inorder(root->lchild);
    cout << root->data << " ";
    inorder(root->rchild);
  }
}
void Tree::postorder(Node *root)
{
  if (root)
  {
    postorder(root->lchild);
    postorder(root->rchild);
    cout << root->data << " ";
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
  root->lchild = root->rchild = NULL;
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
      t->lchild = t->rchild = NULL;
      p->lchild = t;
      q.emplace(t);
    }
    cout << "Enter Right Child of " << p->data << " :: ";
    cin >> x;
    if (x != -1)
    {
      t = new Node;
      t->data = x;
      t->lchild = t->rchild = NULL;
      p->rchild = t;
      q.emplace(t);
    }
  }
}

int main()
{
  Tree t;
  t.create();
  t.display(4);
  cout << endl
       << t.count();
  cout << endl
       << t.height();
  return 0;
}
