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

void Insert(int pos, int x){
	Node *temp = new Node, *p = first;
	temp->data = x;
	temp->next = temp->prev = NULL;	
	if(pos == 0){
		temp->next = first;
		if(first != NULL)
			first->prev = temp;
		first = temp;
	}
	else{
		for(int i = 0; i < pos - 1; i++){
			p = p->next;
		}
		temp->prev = p;
		temp->next = p->next;
		if(p->next != NULL){
			p->prev = temp;
		}
		p->next = temp;
	}
}

int main(){
	vector<int> A = {3, 5, 4, 9, 3};
	create(A);
	Display();
	Insert(2,3);
	Insert(5,4);
	cout<<endl<<endl<<"List After Insertion :: ";
	Display();
	return 0;
}

