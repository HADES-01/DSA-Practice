#include<iostream>
using namespace std;

int main()
{
	int A[3][4] = {{1,2,3,4},{2,4,6,8},{1,3,5,7}}; //Created in stack

	int *B[3]; //Partially in Heap
	for(int i = 0; i < 3; i++)
		B[i] = new int[4];

	int **C;
	C = new int*[3]; //Completely in heap
	for(int i = 0; i < 3; i++)
		C[i] = new int[4];

	//Loop to access values of 2D Array

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
