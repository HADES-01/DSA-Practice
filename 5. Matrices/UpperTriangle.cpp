#include<iostream>
using namespace std;

class UpperTriangle{
	int *A;
	int m;
	public:
		UpperTriangle(int n){
			this->m = n;
			A = new int[(m * (m + 1)) / 2];
		}
		void set(int i, int j, int a);
		int get(int i, int j);
		void Display();
};

void UpperTriangle::set(int i, int j, int a){
	if(i <= j){
		A[(m * (i - 1) - (((i -2) * (i - 1)) / 2)) +  (i - j)] = a;
	}
}

int UpperTriangle::get(int i, int j){
	if(i <= j){
		return A[(m * (i - 1) - (((i -2) * (i - 1)) / 2)) +  (i - j)];
	}
	return 0;
}

void UpperTriangle::Display(){
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= m; j++){
			if(i <= j){
				cout<<A[(m * (i - 1) - (((i -2) * (i - 1)) / 2)) +  (i - j)]<<" ";
			}
			else{
				cout<<0<<" ";
			}
		}
		cout<<endl;
	}
}

int main(){
	UpperTriangle M(5);
	for(int i = 1; i <= 5; i++){
		for(int j = 1; j <= 5; j++){
			M.set(i,j,4);
		}
	}
	M.Display();
	return 0;
}

