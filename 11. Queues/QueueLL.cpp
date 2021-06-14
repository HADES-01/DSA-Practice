#include "bits/stdc++.h"
using namespace std;

struct Node{
	int data;
	Node *next;
};

class Queue{
	private:
		int size;
		Node *front;
		Node *rear;
	public:
		Queue(){
			this->front = this->rear = NULL;
		}
		void enqueue(int x);
		int dequeue();
		void display();
};

void Queue::enqueue(int x){
	Node *t = new Node;
	if(t == NULL){
		cout << "Heap is Full" << endl;
	} else {
		t->data = x;
		t->next = NULL;
		if(front == NULL) front = rear = t;
		else {
			rear->next = t;
			rear = t;
		}
	}
}

int Queue::dequeue(){
	int x = -1;
	if(front == NULL){
		cout << "Queue is Empty" << endl;
	} else {
		Node *t;
		t = front;
		front = front->next;
		x = t->data;
		delete t;
	}
	return x;
}

void Queue::display(){
	if(front == NULL){
		cout << "Queue is Empty" << endl;
		return;
	}
	Node *t = front;
	while(t != rear){
		cout << t->data << " ";
		t = t->next;
	}
	cout << endl;
}

int main(){
	Queue q;
	q.enqueue(10);
	q.enqueue(14);
	q.enqueue(34);
	q.enqueue(34);
	q.enqueue(34);
	q.display();
	cout << q.dequeue() << endl;
	q.display();
	return 0;
}

