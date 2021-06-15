#include "bits/stdc++.h"
using namespace std;

struct Node
{
  struct Node *lchild;
  int data;
  struct Node *rchild;
};

class BST
{
  Node *root;

public:
  BST()
  {
    root = NULL;
  }
  BST(vector<int>, int);
  Node *insert(Node *, int);
  Node *search(Node *, int);
  Node *inPre(Node *);
  Node *inSucc(Node *);
  Node *Delete(Node *, int);
  void createFromPre(vector<int>);
  Node *createFromPost(vector<int> &, int *, int, int, int, int);
  void Delete(int key)
  {
    root = Delete(root, key);
  }
  int height(Node *);
  int height()
  {
    return height(root);
  }
  int search(int key)
  {
    Node *t = search(root, key);
    return t != NULL;
  }
  void insert(int key)
  {
    root = insert(root, key);
  }
  void inorder(Node *);
  void inorder()
  {
    inorder(root);
  }
};

int BST::height(Node *p)
{
  int x, y;
  if (p)
  {
    x = height(p->lchild);
    y = height(p->rchild);
    return x > y ? x + 1 : y + 1;
  }
  return 0;
}

Node *BST::Delete(Node *p, int key)
{
  Node *q = NULL;
  if (!p)
  {
    return NULL;
  }
  if (!p->lchild && !p->rchild && p->data == key)
  {
    if (p == root)
      root = NULL;
    delete p;
    return NULL;
  }
  if (p->data > key)
  {
    p->lchild = Delete(p->lchild, key);
  }
  else if (p->data < key)
  {
    p->rchild = Delete(p->rchild, key);
  }
  else
  {
    if (height(p->lchild) > height(p->rchild))
    {
      q = inPre(p->lchild);
      p->data = q->data;
      p->lchild = Delete(p->lchild, q->data);
    }
    else
    {
      q = inSucc(p->rchild);
      p->data = q->data;
      p->rchild = Delete(p->rchild, q->data);
    }
  }
  return p;
}

Node *BST::inPre(Node *p)
{
  while (p && p->rchild)
  {
    p = p->rchild;
  }
  return p;
}

Node *BST::inSucc(Node *p)
{
  while (p && p->lchild)
  {
    p = p->lchild;
  }
  return p;
}

void BST::inorder(Node *p)
{
  if (p)
  {
    inorder(p->lchild);
    cout << p->data << " ";
    inorder(p->rchild);
  }
}

Node *BST::search(Node *p, int key)
{
  if (!p)
    return NULL;
  else if (p->data == key)
    return p;
  else if (p->data < key)
    return search(p->rchild, key);
  else
    return search(p->lchild, key);
}

Node *BST::insert(Node *p, int key)
{
  Node *t;
  if (!p)
  {
    t = new Node;
    t->data = key;
    t->lchild = t->rchild = NULL;
    return t;
  }
  if (key < p->data)
  {
    p->lchild = insert(p->lchild, key);
  }
  else if (key > p->data)
  {
    p->rchild = insert(p->rchild, key);
  }
  return p;
}

BST::BST(vector<int> a, int type)
{
  root = NULL;
  if (type == 0)
  {
    for (auto el : a)
    {
      insert(el);
    }
  }
  else if (type == 1)
  {
    createFromPre(a);
  }
  else
  {
    int i = a.size() - 1;
    root = createFromPost(a, &i, a[i], INT_MIN, INT_MAX, a.size());
  }
}

void BST::createFromPre(vector<int> a)
{
  int i = 0, n = a.size();
  Node *p, *t;
  stack<Node *> st;
  root = new Node;
  root->data = a[i++];
  root->lchild = root->rchild = NULL;
  p = root;
  while (i < n)
  {
    int comp = p->data;
    if (comp > a[i])
    {
      t = new Node;
      t->data = a[i++];
      t->lchild = t->rchild = NULL;
      p->lchild = t;
      st.push(p);
      p = t;
    }
    else
    {
      Node *x = !st.empty() ? st.top() : NULL;
      int comp2 = x ? x->data : INT_MAX;
      if ((a[i] > comp && comp2 > a[i]))
      {
        t = new Node;
        t->data = a[i++];
        t->rchild = t->lchild = NULL;
        p->rchild = t;
        p = t;
      }
      else
      {
        p = st.top();
        st.pop();
      }
    }
  }
}

Node *BST::createFromPost(vector<int> &a, int *idx, int key, int min, int max, int size)
{
  if (*idx < 0)
  {
    return NULL;
  }
  Node *root = NULL;
  if (key < max && key > min)
  {
    root = new Node;
    root->data = key;
    root->lchild = root->rchild = NULL;
    *idx = *idx - 1;
    if (*idx >= 0)
    {
      root->rchild = createFromPost(a, idx, a[*idx], key, max, size);
      root->lchild = createFromPost(a, idx, a[*idx], min, key, size);
    }
  }
  return root;
}

int main()
{
  BST a({1, 7, 5, 50, 40, 10}, 2);
  // a.insert(7);
  // a.insert(9);
  a.inorder();
  // cout << (a.search(5) ? "" : "Not") << " Found ";
  a.Delete(7);
  a.inorder();
  return 0;
}
