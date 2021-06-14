#include <iostream>
#include <cstring>
#include <math.h>
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

bool isOperand(char a){
	if(a == '+' || a == '-' || a == '*' || a == '/' || a == '^' || a == '(' || a == ')') return 0;
	return 1;
}

int outPre(char a){
	if(a == '+' || a == '-') return 1;
	else if(a == '*' || a == '/') return 3;
	else if(a == '^') return 6;
	else if(a == '(') return 7;
	return 0;
}

int inPre(char a){
	if(a == '+' || a == '-') return 2;
	else if(a == '*' || a == '/') return 4;
	else if(a == '^') return 5;
	return 0;
	
}

char* Postfix(char* infix){
	char* postfix = new char[strlen(infix)];
	Stack st;
	st.push('#');
	int i = 0, j = 0;
	while(infix[i] != '\0'){
		if(isOperand(infix[i])) postfix[j++] = infix[i++];
		else{
			if(outPre(infix[i]) > inPre(st.stackTop())){
				st.push(infix[i++]);
			} else {
				postfix[j++] = st.pop();
				if(infix[i++] == ')') st.pop();
			}
		}
	}
	while(!st.isEmpty()){
		postfix[j++] = st.pop();
	}
	postfix[j - 1] = '\0';
	return postfix;
}

int PostfixEval(char* postfix){
	Stack st;
	for(int i = 0; i < strlen(postfix); i++){
		if(isOperand(postfix[i])) st.push(postfix[i] - '0');
		else{
			int x2 = st.pop(), x1 = st.pop();
			switch(postfix[i]){
				case '+':
					st.push(x1 + x2);
					break;
				case '-':
					st.push(x1 - x2);
					break;
				case '*':
					st.push(x1 * x2);
					break;
				case '/':
					st.push(x1 / x2);
					break;
				case '^':
					st.push(pow(x1, x2));
					break;
			}
		}
	}
	return st.pop();
}


int main() {
	char s[] = "((3+4)*5)-6^2^2";
	char *p  = Postfix(s);
	cout << s << " -> "<< p << " = " << PostfixEval(p);
	return 0;
}

