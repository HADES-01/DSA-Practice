#include "bits/stdc++.h"
using namespace std;

struct Node
{
  struct Node *left;
  int data;
  int height;
  struct Node *right;
  int nodeHeight()
  {
    int a = left ? left->height : 0, b = right ? right->height : 0;
    return a > b ? a + 1 : b + 1;
  }
  int balFact()
  {
    int a = left ? left->height : 0, b = right ? right->height : 0;
    return a - b;
  }
  Node *LLRotate()
  {
    Node *pl = this->left;
    Node *plr = pl->right;
    pl->right = this;
    this->left = plr;
    this->height = this->nodeHeight();
    pl->height = pl->nodeHeight();
    return pl;
  }
  Node *LRRotate()
  {
    Node *pl = this->left;
    Node *plr = pl->right;
    pl->right = plr->left;
    this->left = plr->right;
    plr->right = this;
    plr->left = pl;
    pl->height = pl->nodeHeight();
    plr->height = plr->nodeHeight();
    this->height = this->nodeHeight();
    return plr;
  }
  Node *RRRotate()
  {
    Node *pr = this->right;
    Node *prl = pr->left;
    pr->left = this;
    this->right = prl;
    this->height = this->nodeHeight();
    pr->height = pr->nodeHeight();
    return pr;
  }
  Node *RLRotate()
  {
    Node *pr = this->right;
    Node *prl = pr->left;
    pr->left = prl->left;
    this->right = prl->right;
    prl->left = this;
    prl->right = pr;
    pr->height = pr->nodeHeight();
    prl->height = prl->nodeHeight();
    this->height = this->nodeHeight();
    return prl;
  }
};

class AVL
{
  Node *root;

public:
  AVL()
  {
    root = NULL;
  }
  AVL(vector<int>);
  Node *insert(Node *, int);
  Node *inPre(Node *);
  Node *inSucc(Node *);
  Node *Delete(Node *, int);
  void Delete(int key)
  {
    root = Delete(root, key);
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

Node *AVL::Delete(Node *p, int key)
{
  Node *q = NULL;
  if (!p)
  {
    return NULL;
  }
  if (!p->left && !p->right && p->data == key)
  {
    if (p == root)
      root = NULL;
    delete p;
    return NULL;
  }
  if (p->data > key)
  {
    p->left = Delete(p->left, key);
  }
  else if (p->data < key)
  {
    p->right = Delete(p->right, key);
  }
  else
  {
    if (p->left->nodeHeight() > p->right->nodeHeight())
    {
      q = inPre(p->left);
      p->data = q->data;
      p->left = Delete(p->left, q->data);
    }
    else
    {
      q = inSucc(p->right);
      p->data = q->data;
      p->right = Delete(p->right, q->data);
    }
  }
  p->height = p->nodeHeight();

  if (p->balFact() == 2 && p->left->balFact() == 1)
  {
    return p->LLRotate();
  }
  else if (p->balFact() == 2 && p->left->balFact() == -1)
  {
    return p->LRRotate();
  }
  else if (p->balFact() == -2 && p->right->balFact() == -1)
  {
    return p->RRRotate();
  }
  else if (p->balFact() == -2 && p->right->balFact() == 1)
  {
    return p->RLRotate();
  }
  return p;
}

Node *AVL::inPre(Node *p)
{
  while (p && p->right)
  {
    p = p->right;
  }
  return p;
}

Node *AVL::inSucc(Node *p)
{
  while (p && p->left)
  {
    p = p->left;
  }
  return p;
}

void AVL::inorder(Node *p)
{
  if (p)
  {
    inorder(p->left);
    cout << p->data << " ";
    inorder(p->right);
  }
}

Node *AVL::insert(Node *p, int key)
{
  Node *t;
  if (!p)
  {
    t = new Node;
    t->data = key;
    t->left = t->right = NULL;
    t->height = 1;
    return t;
  }
  if (key < p->data)
  {
    p->left = insert(p->left, key);
  }
  else if (key > p->data)
  {
    p->right = insert(p->right, key);
  }
  p->height = p->nodeHeight();

  if (p->balFact() == 2 && p->left->balFact() == 1)
  {
    return p->LLRotate();
  }
  else if (p->balFact() == 2 && p->left->balFact() == -1)
  {
    return p->LRRotate();
  }
  else if (p->balFact() == -2 && p->right->balFact() == -1)
  {
    return p->RRRotate();
  }
  else if (p->balFact() == -2 && p->right->balFact() == 1)
  {
    return p->RLRotate();
  }
  return p;
}

AVL::AVL(vector<int> a)
{
  root = NULL;
  for (auto el : a)
  {
    insert(el);
  }
}

int main()
{
  AVL a({10, 20, 40, 90});
  a.insert(50);
  a.insert(70);
  a.insert(60);
  a.Delete(40);
  a.inorder();
  return 0;
}
