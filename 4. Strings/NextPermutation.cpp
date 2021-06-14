#include<iostream>
using namespace std;

void Perm(char S[], int k)
{
	static int F[10] = {0};
	static char Res[10] = "a";
	if(S[k] == '\0')
	{
		Res[k] = '\0';
		cout<<Res<<endl;
		k = 0;
	}
	else
	{
		for(int i = 0; S[i] != '\0'; i++)
		{
			if(F[i] == 0)
			{
				Res[k] = S[i];
				F[i] = 1;
				Perm(S, k + 1);
				F[i] = 0;
			}
		}
	}
}

void Swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void Perm2(char S[], int l, int h)
{
	if(l == h)
	{
		cout<<S<<endl;
	}
	else
	{
		for(int i = l; i <= h; i++)
		{
			Swap(&S[i], &S[l]);
			Perm2(S, l + 1, h);
			Swap(&S[i], &S[l]);
		}
	}
}

int main()
{
	char A[] = "ABCD";
	Perm2(A, 0, 3);
	return 0;
}

