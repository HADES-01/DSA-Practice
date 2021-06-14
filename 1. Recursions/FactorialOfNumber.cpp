#include<iostream>
using namespace std;

int fact_recursive(int n){
	if(n < 0){
		cout<<"Factorial his not Possible";
		return 0;
	}
	if(n == 0){
		return 1;
	}
	else{
		return fact_recursive(n - 1) * n;
	}
}

int fact_loop(int n){
	if(n < 0){
		cout<<"Factorial his not Possible";
		return 0;
	}
	int fact = 1;
	for(int i = 1; i <= n; i++){
		fact *= i;
	}
	return fact;
}

int main(){
	int r = 0;
	r = fact_loop(5);
	cout<<r;
	return 0;
}

