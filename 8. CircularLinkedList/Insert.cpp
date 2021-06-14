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

void Insert(int x, int pos){
	Node *p = Head, *temp;
	temp->data = x;
	temp->next = NULL;
	if(pos < 0 || pos > Length())
		return;
	if(pos == 0){
		if(Head == NULL){
			Head = temp;
			temp->next = temp;
		}
		else{
			while(p->next != Head){
				p = p->next;
			}
			p->next = temp;
			temp->next = Head;
			Head = temp;
		}
	}
	else{
		for(int i = 0; i < pos - 1; i++){
			p = p->next;
		}
		temp->next = p->next;
		p->next = temp;
	}
}

int main(){
	vector<int> A = {3, 5 ,3, 9, 1, 9};
	Create(Head, A);
	Display(Head);
	Insert(15, 0);
	cout<<endl<<endl<<"Circular Linked List after Insertion :: ";
	Display(Head);
	return 0;
}

