#include "bits/stdc++.h"
using namespace std;

struct Node
{
  Node *child[26];
  bool isEOW;
  Node()
  {
    isEOW = false;
    for (int i = 0; i < 26; i++)
    {
      child[i] = NULL;
    }
  }
  bool notEmpty()
  {
    for (auto a : child)
    {
      if (a)
        return true;
    }
    return false;
  }
};

class Trie
{
  Node *root;

public:
  Trie()
  {
    root = new Node;
  }
  Trie(vector<string>);
  void insert(string s);
  bool search(string s);
  Node *Delete(Node *, string &, int);
  void delKey(string s);
  void display();
};

Trie::Trie(vector<string> a)
{
  root = new Node;
  for (auto str : a)
  {
    this->insert(str);
  }
}

void Trie::insert(string s)
{
  Node *curr = root;
  for (int i = 0; i < s.size(); i++)
  {
    int a = s[i] - 'a';
    if (!curr->child[a])
    {
      curr->child[a] = new Node;
    }
    curr = curr->child[a];
  }
  curr->isEOW = true;
}

bool Trie::search(string s)
{
  Node *curr = root;
  for (int i = 0; i < s.size(); i++)
  {
    int a = s[i] - 'a';
    if (!curr->child[a])
    {
      return false;
    }
    curr = curr->child[a];
  }
  return curr->isEOW;
}

Node *Trie::Delete(Node *root, string &s, int idx)
{
  if (root == NULL)
    return NULL;
  if (idx == s.size())
  {
    if (root->notEmpty())
    {
      root->isEOW = false;
      return root;
    }
    delete root;
    return NULL;
  }
  int a = s[idx] - 'a';
  root->child[a] = Delete(root->child[a], s, idx + 1);
  if (root->notEmpty())
    return root;
  delete root;
  return NULL;
}

void Trie::delKey(string s)
{
  root = Delete(root, s, 0);
}

void displayUtil(Node *root, vector<char> &a)
{
  if (root->isEOW)
  {
    for (char ch : a)
    {
      cout << ch;
    }
    cout << " ";
  }
  for (int i = 0; i < 26; i++)
  {
    char some = 'a' + i;
    if (root->child[i])
    {
      a.push_back(some);
      displayUtil(root->child[i], a);
    }
  }
  a.pop_back();
}

void Trie::display()
{
  vector<char> a;

  a.push_back(' ');
  displayUtil(root, a);
}

int main()
{
  Trie t({"geek", "geeks", "bat", "bad", "zoo"});
  cout << t.search("geek") << endl;
  // t.delKey("geek");
  cout << t.search("bad");
  t.display();
  return 0;
}
