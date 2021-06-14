#include "bits/stdc++.h"
using namespace std;

class Heap
{
  int *arr;
  int n;
  int size;

public:
  Heap();
  Heap(vector<int>);
  void insert(int);
  void display();
  int Delete();
  void heapSort();
};

void Heap::display()
{
  for (int i = 1; i <= this->size; i++)
  {
    cout << arr[i] << " ";
  }
}

Heap::Heap()
{
  this->size = 0;
  this->n = 2;
  this->arr = new int[n];
  this->arr[0] = 0;
}

void Heap::insert(int key)
{
  if (this->n == this->size + 1)
  {

    this->n *= 2;
    int *temp = this->arr;
    this->arr = new int[n];
    for (int i = 0; i <= this->size; i++)
    {
      arr[i] = temp[i];
    }
  }

  this->size += 1;
  int i = this->size;
  while (i > 1 && arr[i / 2] < key)
  {
    arr[i] = arr[i / 2];
    i = i / 2;
  }
  arr[i] = key;
}

int Heap::Delete()
{
  int x = arr[1];
  arr[1] = arr[size];
  int i = 1, j = 2;
  while (j < size)
  {
    if (arr[j] < arr[j + 1])
      j += 1;
    if (arr[i] < arr[j])
    {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i = j;
      j = 2 * i;
    }
    else
    {
      break;
    }
  }
  size -= 1;
  arr[size + 1] = x;
  return x;
}

void Heap::heapSort()
{
  int s = size;
  for (int i = 1; i <= s; i++)
  {
    this->Delete();
  }
  for (int i = 1; i <= s; i++)
  {
    cout << arr[i] << " ";
  }
}

int *Heapify(vector<int> a)
{
  int l = a.size();
  int *arr = new int[l + 1];
  for (int i = 0; i < l; i++)
  {
    arr[i + 1] = a[i];
  }
  int i = l, j = i * 2;
  int k = 0;
  while (i > 0)
  {
    ++k;
    j = 2 * i;
    if (j > l)
    {
      i--;
      continue;
    }
    if (arr[j] < arr[j + 1])
    {
      j += 1;
    }
    if (arr[i] < arr[j])
    {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i--;
      if (i == 0)
        i = j;
    }
    else
    {
      i--;
    }
  }
  cout << k << endl;
  return arr;
}

Heap::Heap(vector<int> a)
{
  int l = a.size();
  this->size = l;
  this->n = l;
  this->arr = new int[l + 1];
  this->arr[0] = 0;
  arr = Heapify(a);
}

int main()
{
  Heap h({10, 20, 30, 25, 5, 40, 35, 9, 4, 2, 80});
  h.display();
  cout << endl
       << "Sorted order :: ";
  h.heapSort();
  return 0;
}
