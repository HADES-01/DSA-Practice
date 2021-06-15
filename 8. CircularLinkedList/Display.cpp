#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *next;
}*Head = NULL;

void Create(Node *p, vector<int> A){
	Node *t, *last;
	Head = new Node;
	Head->data = A[0];
	Head->next = Head;
	last = Head;
	for(int i = 1; i < A.size(); i++){
		t = new Node;
		last->next = t;
		t->data = A[i];
		t->next = Head;
		last = t;
	}
}

void Display(Node *p){
	do{
		cout<<p->data<<" ";
		p = p->next;
	}while(p != Head);
}

void DisplayRecur(Node *p){
	static int flag = 0;
	if(p != Head || flag == 0){
		flag = 1;
		cout<<p->data<<" ";
		DisplayRecur(p->next);
	}
	flag = 0;
}

int main(){
	vector<int> A = {3, 5 ,3, 9, 1, 9};
	Create(Head, A);
	Display(Head);
	cout<<endl<<endl;
	DisplayRecur(Head);
	return 0;
}

