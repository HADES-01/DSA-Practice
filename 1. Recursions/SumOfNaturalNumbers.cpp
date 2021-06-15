#include<iostream>
using namespace std;

int sum_recursive(int n){
	if(n == 0){
		return 0;
	}
	else{
		return sum_recursive(n - 1) + n;
	}
}

int sum_loop(int n){
	int sum = 0;
	for(int i = 1; i <= n; i++){
		sum += i;
	}
	return sum;
}

int sum_formula(int n){
	return (n * (n + 1)) / 2;
}

int main(){
	int r = 0;
	r = sum_formula(5);
	cout<<r<<" ";
	return 0;
}

