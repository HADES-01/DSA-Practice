#include<bits/stdc++.h>
using namespace std;


struct Node{
	struct Node *prev;
	int data;
	struct Node *next;
}*first = NULL;

void create(vector<int> A){
	Node *temp = new Node, *p = NULL;
	temp->data = A[0];
	temp->next = temp->prev = NULL;
	first = temp;
	p = first;
	for(int i = 1; i < A.size(); i++){
		temp = new Node;
		temp->data = A[i];
		p->next = temp;
		temp->prev = p;
		temp->next = NULL;
		p = temp;
	}
}

void Display(){
	Node *p = first;
	while(p){
		cout<<p->data<<"->";
		p = p->next;
	}
}

void Reverse(){
	Node *p = first, *temp = NULL;
	while(p){
		temp = p->prev;
		p->prev = p->next;
		p->next = temp;
		p = p->prev;
		if(p != NULL && p->next == NULL){
			first = p;
		}
	}
}

int main(){
	vector<int> A = {3, 5, 4, 9, 3};
	create(A);
	Display();
	Reverse();
	cout<<endl<<endl<<"List After Reversal :: ";
	Display();
	return 0;
}

