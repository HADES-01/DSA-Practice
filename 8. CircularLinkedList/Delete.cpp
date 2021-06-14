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

int Length(){
	Node *p = Head;
	int ctr = 0;
	do{
		p = p->next;
		ctr++;
	}while(p != Head);
	return ctr;
}

int Delete(int pos){
	Node *p = Head, *q = NULL;
	int x = -1;
	if(pos < 0 || pos > Length())
		return x;
	if(pos == 0){
		while(p->next != Head) 
			p = p->next;
		x = Head->data;
		if(Head == p){
			delete Head;
			Head = NULL;
		}
		else{
			p->next = Head->next;
			delete Head;
			Head = p->next;
		}
	}
	else{
		for(int i = 0; i < pos - 2; i++){
			p = p->next;
		}
		q = p->next;
		p->next = q->next;
		x = q->data;
		delete q;
	}
	return x;
}

int main(){
	vector<int> A = {3, 5 ,3, 9, 1, 9};
	Create(Head, A);
	Display(Head);
	cout<<endl<<endl<<"Circular Linked List after Deletion of "<<Delete(3)<<" :: ";
	Display(Head);
	return 0;
}

