#include<bits/stdc++.h>
using namespace std;

class Elements{
	public:
	int i;
	int j;
	int x;
};
class Sparse{
	int m;
	int n;
	int num;
	Elements *e;
	public:
		Sparse(int m, int n, int num){
			this->m = m;
			this->n = n;
			this->num = num;
			e = new Elements[this->num];
		}
		~Sparse(){
			delete []e;
		}
		Sparse operator+(Sparse &s);
		friend istream & operator>>(istream &is, Sparse &s);
		friend ostream & operator<<(ostream &os, Sparse &s);
};

Sparse Sparse::operator+(Sparse &s){
	int i, j, k;
	i = j = k = 0;
	Sparse Sum(m, n, num + s.num);
	while(i < num && j < s.num){
		if(e[i].i < s.e[j].i){
			Sum.e[k++] = e[i++];
		}
		else if(e[i].i > s.e[j].i){
			Sum.e[k++] = s.e[j++];
		}
		else{
			if(e[i].j < s.e[j].j){
				Sum.e[k++] = e[i++];
			}
			else if(e[i].j > s.e[j].j){
				Sum.e[k++] = s.e[j++];
			}
			else{
				Sum.e[k] = e[i++];
				Sum.e[k++].x += s.e[j++].x;
			}
		}
	}
	for(; i < num; i++){
		Sum.e[k++] = e[i];
	}
	for(; j < s.num; j++){
		Sum.e[k++] = s.e[j];
	}
	Sum.num = k;
	return Sum;
}

istream & operator>>(istream &is, Sparse &s){
	cout<<"Enter Non-Zero Elements :: ";
	for(int i = 0;i < s.num; i++){
		cin>>s.e[i].i>>s.e[i].j>>s.e[i].x;
	}
	return is;
}
ostream & operator<<(ostream &os, Sparse &s){
	int k = 0;
	for(int i = 0; i < s.m; i++){
		for(int j = 0; j < s.n; j++){
			if(s.e[k].i == i && s.e[k].j == j){
				cout<<s.e[k++].x<<" ";
			}
			else{
				cout<<"0 ";
			}
		}
		cout<<endl;
	}
	return os;
}

int main(){
	
	Sparse S1(5,5,5), S2(5,5,5);
	cin >> S1;
	cin >> S2;
	Sparse sum = S1 + S2;
	cout<<"\n First Matrix :: \n"<<S1;
	cout<<"\n Second Matrix :: \n"<<S2;
	cout<<"\n Sum Matrix :: \n"<<sum;
	return 0;
}

