#include<iostream>
using namespace std;

class Matrix
{
	private:
		int *A;
		int n;
	public:
		Matrix(int n)
		{
			this->n = n;
			A = new int[n];
		}
		void Set(int i, int j, int x);
		int Get(int i, int j);
		void Display();
		~Matrix()
		{
			delete []A;
		}
};

void Matrix::Set(int i, int j, int x)
{
	if(i == j)
	{
		A[i - 1] = x;
	}
}

int Matrix::Get(int i, int j)
{
	if(i == j)
		return A[i - 1];
	else
		return 0;
}

void Matrix::Display()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i == j)
				cout<<A[i]<<" ";
			else
				cout<<"0 ";
		}
		cout<<endl;
	}
}

int main(){
	Matrix m(4);
	m.Set(1,1,5);
	m.Set(4,4,5);
	m.Set(2,0,5);
	m.Set(3,3,5);
	m.Display();
	cout<<endl<<m.Get(1,1);
	return 0;
}

