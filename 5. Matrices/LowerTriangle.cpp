#include<iostream>
using namespace std;

class Lower{
	int *A;
	int n;
	public:
		Lower(int n)
		{
			this->n = n;
			A = new int[(n * ( n + 1 )) / 2];
		}
		~Lower()
		{
			delete []A;
		}
		void Set(int i, int j, int x);
		int Get(int i, int j);
		void Display();
};

void Lower::Set(int i, int j, int x)
{
	if(i >= j)
	{
		A[i*(i - 1)/2 + j - 1] = x;
	}
}

int Lower::Get(int i, int j)
{
	if(i >= j)
	{
		return A[(i * (i - 1) / 2) + (j - 1)];
	}
	return 0;
}

void Lower::Display()
{
	for(int i = 1; i < n; i++)
	{
		for(int j = 1; j < n; j++)
		{
			if(i >= j)
			{
				cout<<A[i * (i - 1) / 2 + (j - 1)]<<" ";
			}
			else
			{
				cout<<"0 ";
			}
		}
		cout<<endl;
	}
}

int main()
{
	int n = 5;
	Lower M(n);
	M.Set(1,1,1);
	M.Set(2,1,2);
	M.Set(2,2,3);
	M.Set(3,1,4);
	M.Set(3,2,5);
	M.Set(3,3,6);
	M.Set(4,1,7);
	M.Set(5,1,8);
	M.Display();
	return 0;
}

