#include<iostream>
using namespace std;

int fibonacci(int n)
{
	if(n <= 1)
	{
        return n;
	}
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int f[10];

int fibonacci_memoization(int n)
{
    if(n <= 1)
    {
		f[n] = n;
        return n;
    }
    if(f[n - 1] == -1)
    {
		f[n - 1] = fibonacci_memoization(n - 1);
    }
    if(f[n - 2] == -1)
    {
		f[n - 2] = fibonacci_memoization(n - 2);
    }
    return f[n - 1] + f[n - 2];
}

int main()
{
	int n = 19;
	for(int i = 0; i<= n; i++){
		f[i] = -1;
	}
    cout<<fibonacci_memoization(n);
	return 0;
}

