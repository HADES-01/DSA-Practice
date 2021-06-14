#include "bits/stdc++.h"
using namespace std;

class Queue{
	private:
		int size;
		int front;
		int rear;
		int *Q;
	public:
		Queue(int size){
			this->size = size;
			this->Q = new int[size];
			this->front = this->rear = -1;
		}
		void enqueue(int x);
		int dequeue();
		void display();
};

void Queue::enqueue(int x){
	if(this->rear == this->size){
		cout << "Queue is Full" << endl;
	} else {
		this->Q[++this->rear] = x;
	}
}

int Queue::dequeue(){
	int x = -1;
	if(this->front == this->rear){
		cout << "Queue is Empty" << endl;
	} else {
		x = this->Q[++this->front];
	}
	return x;
}

void Queue::display(){
	if(this->front == this->rear){
		cout << "Queue is Empty" << endl;
		return;
	}
	int temp = this->front + 1;
	while(temp <= rear){
		cout << this->Q[temp++] << " ";
	}
	cout << endl;
	
}

int main(){
	Queue q(5);
	q.enqueue(5);
	q.enqueue(10);
	q.enqueue(155);
	q.enqueue(12);
	q.enqueue(13);
	q.display();
	cout << q.dequeue() << endl;
	q.dequeue();
	q.display();
	q.enqueue(14);
	q.enqueue(15);
	q.display();
	return 0;
}

