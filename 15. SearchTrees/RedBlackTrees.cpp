#include "bits/stdc++.h"
using namespace std;

struct Node
{
  struct Node *left;
  struct Node *right;
  bool isRed;
  int height;
  int data;
  int nodeHeight()
  {
    int a = left ? left->height : 0, b = right ? right->height : 0;
    return a > b ? a + 1 : b + 1;
  }
  Node(int key)
  {
    this->isRed = true;
    this->left = this->right = NULL;
    this->data = key;
  }
  Node *colorChange()
  {
    this->isRed = true;
    this->right->isRed = false;
    this->left->isRed = false;
    return this;
  }

  Node *LLRotation()
  {
    Node *pl = this->left;
    Node *plr = pl->right;
    pl->right = this;
    this->left = plr;
    this->isRed = true;
    pl->isRed = false;
    return pl;
  }
  Node *RRRotation()
  {
    Node *pr = this->right;
    Node *prl = pr->left;
    pr->left = this;
    this->right = prl;
    this->isRed = true;
    pr->isRed = false;
    return pr;
  }
  Node *LRRotation()
  {
    Node *pl = this->left;
    Node *plr = pl->right;
    this->left = plr->right;
    pl->right = plr->left;
    plr->right = this;
    plr->left = pl;
    this->isRed = true;
    plr->isRed = false;
    return plr;
  }
  Node *RLRotation()
  {
    Node *pr = this->right;
    Node *prl = pr->left;
    this->right = prl->left;
    pr->left = prl->right;
    prl->left = this;
    prl->right = pr;
    this->isRed = true;
    prl->isRed = false;
    return prl;
  }
};

class RedBlack
{
  Node *root;

public:
  RedBlack()
  {
    root = NULL;
  }
  RedBlack(vector<int>);
  Node *insert(Node *, int);
  Node *inPre(Node *);
  Node *inSucc(Node *);
  void insert(int key)
  {
    root = insert(root, key);
    root->isRed = false;
  }
  Node *Delete(Node *, int);
  void Delete(int key)
  {
    root = Delete(root, key);
  }
  void inorder(Node *);
  void inorder()
  {
    inorder(root);
  }
};

void RedBlack::inorder(Node *root)
{
  if (root)
  {
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
  }
}

Node *RedBlack::insert(Node *root, int key)
{
  Node *t;
  if (!root)
  {
    t = new Node(key);
    return t;
  }
  if (key < root->data)
  {
    root->left = insert(root->left, key);
  }
  else if (key > root->data)
  {
    root->right = insert(root->right, key);
  }
  if (root->left && root->left->left && root->left->isRed && root->left->left->isRed)
  {
    if (!root->right || !root->right->isRed)
    {
      return root->LLRotation();
    }
    else if (root->right && root->right->isRed)
    {
      return root->colorChange();
    }
  }
  else if (root->left && root->left->right && root->left->isRed && root->left->right->isRed)
  {
    if (!root->right || !root->right->isRed)
    {
      return root->LRRotation();
    }
    else if (root->right && root->right->isRed)
    {
      return root->colorChange();
    }
  }
  else if (root->right && root->right->right && root->right->isRed && root->right->right->isRed)
  {
    if (!root->left || !root->left->isRed)
    {
      return root->RRRotation();
    }
    else if (root->left && root->left->isRed)
    {
      return root->colorChange();
    }
  }
  else if (root->right && root->right->left && root->right->isRed && root->right->left->isRed)
  {
    if (!root->left || !root->left->isRed)
    {
      return root->RLRotation();
    }
    else if (root->left && root->left->isRed)
    {
      return root->colorChange();
    }
  }
  return root;
}

Node *RedBlack::inPre(Node *p)
{
  while (p && p->right)
  {
    p = p->right;
  }
  return p;
}

Node *RedBlack::inSucc(Node *p)
{
  while (p && p->left)
  {
    p = p->left;
  }
  return p;
}

Node *RedBlack::Delete(Node *p, int key)
{
  Node *q = NULL;
  if (!p)
  {
    return NULL;
  }
  if ((!p->left || !p->right) && p->data == key && p->isRed)
  {
    if (p->left)
    {
      p->data = p->left->data;
      delete p->left;
    }
    else if (p->right)
    {
      p->data = p->right->data;
      delete p->right;
    }
    else
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

  return p;
}

RedBlack::RedBlack(vector<int> a)
{
  root = NULL;
  for (auto el : a)
  {
    insert(el);
  }
}

int main()
{
  RedBlack rb({10, 20, 30, 50, 40, 60, 70, 80, 4, 8});
  rb.inorder();
  return 0;
}