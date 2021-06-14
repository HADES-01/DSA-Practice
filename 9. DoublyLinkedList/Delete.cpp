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

int Length(){
	Node *p = first;
	int ctr = 0;
	while(p){
		ctr++;
		p = p->next;
	}
	return ctr;
}

void Delete(int pos){
	if(pos < 1 || pos > Length())
		return;
	Node *p = first;
	if(pos == 1){
		first = first->next;
		if(first != NULL)
			first->prev = NULL;
		delete p;
	}
	else{
		for(int i = 0; i < pos - 1; i++){
			p = p->next;
		}
		p->prev->next = p->next;
		if(p->next)
			p->next->prev = p->prev;
		delete p;
	}
}

int main(){
	vector<int> A = {3, 5, 4, 9, 3, 7, 10};
	create(A);
	Display();
	Delete(1);
	cout<<endl<<endl<<"List After Deletion :: ";
	Delete(2);
	Delete(5);
	Display();
	return 0;
}

