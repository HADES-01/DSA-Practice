#include <iostream>
using namespace std;

class Node {
	public:
		char data;
		Node *next;
};

class Stack {
	private:
		Node *top;
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

bool balanceParan(char *exp){
	Stack st;
	for(int i = 0; exp[i] != '\0'; i++) {
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') st.push(exp[i]);
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
			if(st.isEmpty()) return false;
			if(st.stackTop() + 1 == exp[i] || st.stackTop() + 2 == exp[i]) st.pop();
			else return false;
		}
	}
	return st.isEmpty();
}

int main() {
	char exp[] = "({a+b}*[c+d])[";
	cout << (balanceParan(exp) ? "Yes" : "No");
	return 0;
}

