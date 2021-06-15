#include<iostream>
#include<string.h>
using namespace std;

void DuplicatesBitwise(char A[])
{
	int h = 0, x = 0;
	for(int i = 0; A[i] != '\0'; i++)
	{
		x = 1;
		x = x << A[i] - 97;
		if((h & x) > 0)
		{
			cout<<A[i];
			cout<<" is Duplicate \n";
		}
		else
			h = x | h;
	}
}

int main()
{
	char A[] = "finding a key is a good";
	DuplicatesBitwise(A);
	return 0;
}

