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
		void renqueue(int x);
		int rdequeue();
		void fenqueue(int x);
		int fdequeue();
		void display();
};

void Queue::renqueue(int x){
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

int Queue::rdequeue(){
	int x = -1;
	if(front == NULL){
		cout << "Queue is Empty" << endl;
	} else {
		Node *t = front, *p = rear;
		x = p->data;
		while(t->next != p) t = t->next;
		t->next = NULL;
		delete p;
	}
	return x;
}

void Queue::fenqueue(int x){
	Node *t = new Node;
	if(t == NULL){
		cout << "Heap is Full" << endl;
	} else {
		t->data = x;
		t->next = NULL;
		if(front == NULL) front = rear = t;
		else {
			t->next = front;
			front = t;
		}
	}
}

int Queue::fdequeue(){
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
	while(t != NULL){
		cout << t->data << " ";
		t = t->next;
	}
	cout << endl;
}

int main(){
	Queue q;
	q.fenqueue(10);
	q.renqueue(14);
	q.renqueue(34);
	q.fenqueue(34);
	q.renqueue(34);
	q.display();
	cout << q.rdequeue() << endl;
	q.display();
	return 0;
}

