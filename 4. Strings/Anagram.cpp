#include<iostream>
using namespace std;

bool CheckAnagram(char A[], char B[])
{
	int hash[128] = {0};
	for(int i = 0; A[i] != '\0'; i++)
	{
		hash[A[i]]++;
	}
	for(int i = 0; B[i] != '\0'; i++)
	{
		hash[B[i]]--;
		if(hash[B[i]] < 0)
		{
			return false;
		}
	}
	return true;
}

bool CheckAnagramBitwise(char A[], char B[])
{
	long long int h = 0, x = 0;
	for(int i = 0; A[i] != '\0'; i++)
	{
		x |= (1 << (A[i] - 97));
		cout<<x<<" ";
	}
	cout<<endl;
	for(int i = 0; B[i] != '\0'; i++)
	{
		h = 0;
		h |= (1 << (B[i] - 97));
		cout<<h<<" ";
		if((x & h) != h)
		{
			return 0;
		}
	}
	cout<<endl;
	return 1;
}

int main()
{
	char A[] = "decimal";
	char B[] = "medical";
	cout<<CheckAnagramBitwise(A,B);
//	int x = 1;
//	int y = (97 & 31);
//	cout<<endl<<(x << y);
	return 0;
}

