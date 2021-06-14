#include<iostream>
using namespace std;

struct Elements{
	int i;
	int j;
	int x;
};

struct Sparse{
	int m;
	int n;
	int num;
	struct Elements *e;
};

void create(struct Sparse *S){
	cout<<"Dimensions :: ";
	cin>>S->m>>S->n;
	cout<<"Entger No. of Non-Zero Elements :: ";
	cin>>S->num;
	cout<<"Enter Elements :: ";
	S->e = new struct Elements[S->num]; 
	for(int i = 0; i < S->num; i++){
		cin>>S->e[i].i>>S->e[i].j>>S->e[i].x;
	}
}

void Display(struct Sparse S){
	int k = 0;
	cout<<"\nSparse Matrix :: \n";
	for(int i = 0; i < S.m; i++){
		for(int j = 0; j < S.n; j++){
			if(S.e[k].i == i && S.e[k].j == j){
				cout<<S.e[k++].x<<" ";
			}
			else{
				cout<<"0 ";
			}
		}
		cout<<endl;
	}	
}

struct Sparse* Add(struct Sparse *S1, struct Sparse *S2){
	if(S1->m != S2->m || S1->n != S2->n) return 0;
	int i,j,k;
	i = j = k = 0;
	struct Sparse *Sum;
	Sum = new struct Sparse;
	Sum->e = new struct Elements[S1->num + S2->num];
	while(i < S1->num && j < S2->num){
		if(S1->e[i].i < S2->e[j].i){
			Sum->e[k++] = S1->e[i++];
		}
		else if(S1->e[i].i > S2->e[j].i){
			Sum->e[k++] = S2->e[j++];
		}
		else{
			if(S1->e[i].j < S2->e[j].j){
				Sum->e[k++] = S1->e[i++];
			}
			else if(S1->e[i].j > S2->e[j].j){
				Sum->e[k++] = S2->e[j++];
			}
			else{
				Sum->e[k] = S1->e[i++];
				Sum->e[k++].x += S2->e[j++].x;
			}
		}
	}
	for(; i < S1->num; i++) Sum->e[k++] = S1->e[i];
	for(; j < S2->num; j++) Sum->e[k++] = S2->e[j];
	Sum->m = S1->m;
	Sum->n = S1->n;
	Sum->num = k;
	return Sum;
}

int main(){
	struct Sparse S1, S2, *S3;
	create(&S1);
	create(&S2);
	S3 = Add(&S1, & S2);
	cout<<"\nFirst Matrix :: \n";
	Display(S1);
	cout<<"\nSecond Matrix :: \n";
	Display(S2);
	cout<<"\nSum Matrix :: \n";
	Display(*S3);
	return 0;
}

