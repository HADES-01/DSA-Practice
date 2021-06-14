#include<iostream>
using namespace std;

int fact(int n)
{
	if(n == 0)
	{
		return 1;
	}
	return fact(n - 1) * n;
}

int nCr(int m, int n)
{
	int num, den;
	num = fact(m);
	den = fact(n)*fact(m - n);

	return num / den;
}

int nCr_pascal(int m, int n)
{
	if(n == 0 || n == m)
		return 1;

	return nCr(m - 1, n - 1) + nCr(m - 1, n);
}

int main()
{
	cout<<nCr_pascal(10,5);
	return 0;
}
