#include<iostream>
using namespace std;

template <class T>
class Array{
	private:
		T *A;
		int size;
		int length;

	public:
		Array()
		{
			size = 10;
			length = 0;
			A = new T[size];
		}
		Array(int sz)
		{
			size = sz;
			length = 0;
			A = new T[size];
		}
		~Array()
		{
			delete []A;
		}
		void Display();
		void Append(T x);
		void Insert(int index, T x);
		T Delete(int index);
};

template <class T>
void Array<T>::Display()
{
	cout<<"\nThe elements are :: ";
	for(int i = 0; i < length; i++)
	{
		cout<<A[i]<<" ";
	}
}

template <class T>
void Array<T>::Append(T x)
{
	if(length < size)
	{
		A[length++] = x;
	}
}
template <class T>
void Array<T>::Insert(int index, T x)
{
	if(index >= 0 && index <= length)
	{
		for(int i = length; i > index; i--)
			A[i] = A[i - 1];
		A[index] = x;
		length++;
	}
	else
	{
		cout<<"\nEnter a Valid Index!!!!";
	}
}
template <class T>
T Array<T>::Delete(int index)
{
	if(index < length)
	{
		T x = A[index];
		for(int i = index; i < length - 1; i++)
		{
			A[i] = A[i + 1];
		}
		length--;
		return x;
	}
	else
	{
		cout<<"\n Enter a Valid Index!!!";
		return 0;
	}
}

int main()
{
	Array<char> arr(10);
	
	arr.Append('2');
	arr.Append('4');
	arr.Append('7');
	arr.Display();
	return 0;
}

