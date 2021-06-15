#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *next;
}*firstA = NULL, *firstB = NULL, *firstC = NULL;

Node* create(int n, Node *first){
	struct Node *t, *p = first;
	t = new struct Node;
	t->data = n;
	t->next = NULL;
	if(first != NULL){
		while(p->next){
			p = p->next;
		}
		p -> next = t;
	}
	else{
		first = t;
	}
	return first;
}

void Display(Node *first){
	struct Node *temp = first;
	while(temp != NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
}

Node* Concat(Node *first, Node *second){
	Node *temp = first;
	while(temp->next){
		temp = temp->next;
	}
	temp->next = second;
	return first;
}

int main(){
	vector<int> A = {3,6,3,1,7,6}, B = {13,1,4,9};
	for(int i = 0; i < A.size(); i++){
		firstA = create(A[i], firstA);
	}
	cout<<"List A :: ";
	Display(firstA);
	for(int i = 0; i < B.size(); i++){
		firstB = create(B[i], firstB);
	}
	cout<<endl<<"List B ::";
	Display(firstB);
	cout<<endl;
	firstC = Concat(firstA, firstB);
	cout<<"\nList after Concatinating :: ";
	Display(firstA);
	return 0;
}
