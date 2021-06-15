#include<iostream>
#include<math.h>
using namespace std;

class Term{
	public:
		int coeff;
		int exp;
};

class Poly{
	int n;
	Term *t;
	int x;
	public:
		Poly(int n){
			this->n = n;
			t = new Term[this->n];
		}
		~Poly(){
			delete []t;
		}
		Poly operator+(Poly &p);
		friend istream & operator>>(istream &is, Poly &p);
		friend ostream & operator<<(ostream &os, Poly &p);
		long evaluate();
};

istream & operator>>(istream &is, Poly &p){
	cout<<"Enter Elements :: \n";
	for(int i = 0; i < p.n; i++){
		cout<<"Element "<<i + 1<<"\'s Coeff :: ";
		cin>>p.t[i].coeff;
		cout<<"Element "<<i + 1<<"\'s Exp :: ";
		cin>>p.t[i].exp;
	}
	cout<<"\nEnter value of x :: ";
	cin>>p.x;
	return is;
}

ostream & operator<<(ostream &os, Poly &p){
	cout<<endl;
	for(int i = 0; i < p.n; i++){
		cout<<p.t[i].coeff<<"x^"<<p.t[i].exp<<" + ";
	}
	cout<<"\b\b\b = "<<p.evaluate();
	return os;
}

Poly Poly::operator+(Poly &p){
	int i,j,k;
	i = j = k = 0;
	Poly Sum(n + p.n);
	while(i < n && j < p.n){
		if(t[i].exp > p.t[j].exp){
			Sum.t[k++] = t[i++];;
		}
		else if(t[i].exp < p.t[j].exp){
			Sum.t[k++] = p.t[j++];;
		}
		else{
			Sum.t[k] = t[i++];
			Sum.t[k++].coeff += p.t[j++].coeff;
		}
	}
	for(;i < n; i++){
		Sum.t[k++] = t[i];
	}
	for(; j < p.n; j++){
		Sum.t[k++] = p.t[j];
	}
	Sum.n = k;
	sum.x = x;
	return Sum;
}

long Poly::evaluate(){
	long sum = 0;
	for(int i = 0; i < n; i++){
		sum += t[i].coeff * pow(x, t[i].exp);
	}
	return sum;
}

int main(){
	Poly P1(5), P2(5);
	cin>>P1>>P2;
	Poly P3 = P1 + P2;
	cout<<"\nFirst Polynomial :: "<<P1;
	cout<<"\nSecond Polynomial :: "<<P2;
	cout<<"\nSum is :: "<<P3;
	return 0;
}

