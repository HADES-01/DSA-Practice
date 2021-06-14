#include "bits/stdc++.h"
using namespace std;

struct Node
{
	int data;
	Node *next;
};

class Queue
{
private:
	int size;
	Node *front;
	Node *rear;

public:
	Queue()
	{
		this->front = this->rear = NULL;
	}
	void enqueue(int x);
	int dequeue();
	void display();
	bool isEmpty();
};

bool Queue::isEmpty()
{
	return (front == NULL);
}

void Queue::enqueue(int x)
{
	Node *t = new Node;
	if (t == NULL)
	{
		cout << "Heap is Full" << endl;
	}
	else
	{
		t->data = x;
		t->next = NULL;
		if (front == NULL)
			front = rear = t;
		else
		{
			rear->next = t;
			rear = t;
		}
	}
}

int Queue::dequeue()
{
	int x = -1;
	if (front == NULL)
	{
		cout << "Queue is Empty" << endl;
	}
	else
	{
		Node *t;
		t = front;
		front = front->next;
		x = t->data;
		delete t;
	}
	return x;
}

void Queue::display()
{
	if (front == NULL)
	{
		cout << "Queue is Empty" << endl;
		return;
	}
	Node *t = front;
	while (t != NULL)
	{
		cout << t->data << " ";
		t = t->next;
	}
}

class Priority_Queue
{
	int priors;
	Queue *Q;

public:
	Priority_Queue(int priors)
	{
		this->priors = priors;
		Q = new Queue[priors];
	}
	void enqueue(int data, int priority);
	int dequeue();
	bool isEmpty();
	void display();
};

void Priority_Queue::enqueue(int data, int priority)
{
	if (priority > priors || priority < 1)
	{
		cout << "Invalid Priority" << endl;
		return;
	}
	this->Q[priority - 1].enqueue(data);
}

bool Priority_Queue::isEmpty()
{
	int i = 0;
	while (1)
	{
		if (!Q[i++].isEmpty())
		{
			return false;
		}
	}
	return true;
}

int Priority_Queue::dequeue()
{
	int x = -1;
	if (this->isEmpty())
	{
		cout << "Queue is Empty" << endl;
	}
	else
	{
		int i = 0;
		while (Q[i].isEmpty())
			i++;
		x = Q[i].dequeue();
	}
	return x;
}

void Priority_Queue::display()
{
	for (int i = 0; i < priors; i++)
	{
		if (!Q[i].isEmpty())
		{
			Q[i].display();
		}
	}
	cout << endl;
}

int main()
{
	Priority_Queue pq(4);
	pq.enqueue(355, 2);
	pq.enqueue(4, 1);
	pq.enqueue(5, 3);
	pq.enqueue(6, 2);
	pq.enqueue(7, 3);
	pq.enqueue(8, 2);
	pq.display();
	cout << pq.dequeue() << endl;
	pq.display();
	return 0;
}
