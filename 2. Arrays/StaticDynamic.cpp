#include<iostream>
using namespace std;

int main()
{
	int A[5];  //Static Allocation

	int n = 3;
	cin>>n;
	int B[n];  //Static Allocation


	int *p = new int[5]; //Dynamic Allocation

	delete []p  //Delete to avoid memory leak
	return 0;
}
