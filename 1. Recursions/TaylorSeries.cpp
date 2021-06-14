#include<iostream>
using namespace std;

double taylor_recursive_slow(int m, int n){
	static double p = 1, f = 1;
	double r;
	if(n == 0){
		return 1;
	}
	else{
		r = taylor_recursive_slow(m, n - 1);
		p *= m;
		f *= n;
		return r + p / f;
	}
}

double taylor_recursive_horner(int m, int n){
	static double s = 1;
	if(n == 0){
		return s;
	}
	else{
		s = 1 + m * s / n;
		return taylor_recursive_horner(m, n - 1);
	}
}

double taylor_horner_loop(int m, int n){
	double s = 1;
	for(; n > 0; n--){
		s = 1 + s*m/n;
	}
	return s;
}

double taylor_loop(int m, int n){
	double den = 1, num = 1, s = 1;
	for(int i = 1; i <= n; i++){
		num *= m;
		den *= i;
		s += num / den;
	}
	return s;
}

int main(){
	cout<<taylor_loop(2, 10);
	return 0;
}

