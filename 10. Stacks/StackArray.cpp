#include <iostream>
using namespace std;

struct stack {
	int Top;
	int size;
	int *s;
};

void create(struct stack *st) {
	cout << "Enter the size :: ";
	cin >> st->size;
	st->Top = -1;
	st->s = new int[st->size];
}

void display(struct stack st) {
	for(int i = st.Top; i >= 0; i--) {
		cout << st.s[i] << " ";
	}
	cout << endl;
}

void push(struct stack *st, int x) {
	if(st->Top == st->size - 1) {
		cout<< "Stack Overflow" << endl;
	} else {
		st->Top++;
		st->s[st->Top] = x;
	}
}

int pop(struct stack *st) {
	if(st->Top == -1) {
		cout << "Stak Underflow" << endl;
		return -1;
	} else {
		return st->s[st->Top--];
	}
}

int peek(struct stack st, int index) {
	int x = 1;
	if(st.Top - index + 1 < 0) {
		cout << "Invalid Index" << endl;
	} else {
		return st.s[st.Top - index + 1];
	}
}

bool isEmpty(struct stack st) {
	if(st.Top == -1) return 1;
	else return 0;
}

bool isTop(struct stack st) {
	if(st.Top == st.size - 1) return 1;
	else return 0;
}

int stackTop(struct stack st) {
	return st.s[st.Top];
}

int main(){
	struct stack st;
	create(&st);
	
	push(&st, 10);
	push(&st, 20);
	push(&st, 30);
	push(&st, 40);
	
	cout << peek(st, 3) <<endl;
	
	display(st);
	return 0;
}
