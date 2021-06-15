#include<iostream>
using namespace std;

int exp_recursive_slow(int m, int n){
	if(n == 0){
		return 1;
	}
	else{
		return exp_recursive_slow(m, n - 1) * m;
	}
}

int exp_recursive_fast(int m, int n){
	if(n == 0){
		return 1;
	}
	if(n % 2 == 0){
		return exp_recursive_fast(m * m, n / 2);
	}
	else{
		return exp_recursive_fast(m * m, (n - 1) / 2) * m;
	}
}

int exp_loop(int m, int n){
	int exp = 1;
	for(int i = 1; i <= n; i++){
		exp *= m;
	}
	return exp;
}

int main(){
	int r = 0;
	r = exp_recursive_fast(2, 100);
	cout<<r;
	return 0;
}

