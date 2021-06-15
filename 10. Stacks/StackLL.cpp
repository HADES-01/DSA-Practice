#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node *next;
};

class Stack {
	private:
		Node *top;
		int size;
	public:
		Stack() {
			top = NULL;
		}
		void display();
		void push(int x);
		int pop();
		bool isEmpty();
		bool isFull();
		int stackTop();
};

void Stack::push(int x) {
	Node *t = new Node;
	if(!t) {
		cout << "Stack Overflow" << endl;
	} else {
		t->data = x;
		t->next = top;
		top = t;
	}
}

int Stack::pop() {
	if(!top) {
		cout << "Stack Underflow" << endl;
		return -1;
	} else {
		Node *x = top;
		top = top->next;
		int y = x->data;
		delete x ;
		return y;
	}
}

void Stack::display(){
	Node *p = top;
	while(p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

bool Stack::isEmpty() {
	return top ? 0 : 1;
}

bool Stack::isFull() {
	Node *p = new Node;
	if(!p) return true;
	return false;
}

int Stack::stackTop() {
	return top->data;
}

int main() {
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.display();
	cout << s.pop() << endl;
	s.display();
	return 0;
}

