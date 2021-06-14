#include<iostream>
using namespace std;

class Array{
	private:
		int *A;
		int size;
		int length;
		
	public:
		Array()
		{
			size = 10;
			length = 0;
			A = new int[size];
		}
		Array(int sz)
		{
			size = sz;
			length = 0;
			A = new int[size];
		}
		~Array()
		{
			delete []A;
		}
		void Swap(int *x, int *y);
		void Display();
		void Append(int x);
		void Insert(int index, int x);
		int Delete(int index);
		int LinearSearch(int key);
		int BinarySearch_loop(int key);
		int BinarySearch_recur(int l,int h,int key);
		int Get(int index);
		void Set(int x, int index);
		int Sum();
		float Avg();
		int Max();
		int Min();
		void Reverse();
		void Reverse2();
		void RotateLeft();
		void RotateRight();
		void InsertSorted(int x);
		bool isSorted();
		void Rearrange();
		Array* Merge(Array *arr2);
		Array* Union(Array *arr2);
		Array* Intersection(Array *arr2);
		Array* Difference(Array *arr2);
};

void Array::Display()
{
	cout<<"\nThe elements are :: ";
	for(int i = 0; i < length; i++)
	{
		cout<<A[i]<<" ";
	}
}

void Array::Append(int x)
{
	if(length < size)
	{
		A[length++] = x;
	}
}

void Array::Insert(int index, int x)
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

int Array::Delete(int index)
{
	if(index < length)
	{
		int x = A[index];
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

void Array::Swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int Array::LinearSearch(int key)
{
	for(int i = 0; i < length; i++)
	{
		if(A[i] == key)
		{
//			Swap(&A[i], &A[i-1]);  //Transposition
//			return i - 1;
//			Swap(&A[i], &A[0]);  //Move to Head
//			return 0;
			return i;  //Normal Linear Search
		}
	}
	return -1;
}

int Array::BinarySearch_loop(int key)
{
	int l, h, mid;
	l = 0; h = length - 1;
	while(l < h)
	{
		mid = (l + h) / 2;
		if(key == A[mid])
			return mid;
		else if(key < A[mid])
			h = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}

int Array::BinarySearch_recur(int l,int h,int key)
{
	int mid = 0;
	if(l <= h)
	{
		mid = (l + h) / 2;
		if(A[mid] == key)
			return mid;
		else if(A[mid] > key)
			return BinarySearch_recur(l, mid - 1, key);
		else
			return BinarySearch_recur(mid + 1, h, key);
	}
	return -1;
}

int Array::Get(int index)
{
	if(index >= 0 && index < length)
	{
		return A[index];
	}
}

void Array::Set(int index, int x)
{
	if(index >= 0 && index < length)
	{
		A[index] = x;
	}
}

int Array::Sum()
{
	int sum = 0;
	for(int i = 0; i < length; i++)
	{
		sum += A[i];
	}
	return sum;
}

float Array::Avg()
{
	return float(Sum() / length);
}

int Array::Max()
{
	int max = A[0];
	for(int i = 0; i < length; i++)
	{
		if(max < A[i])
		{
			max = A[i];
		}
	}
	return max;
}

int Array::Min()
{
	int min = A[0];
	for(int i = 0; i < length; i++)
	{
		if(min > A[i])
		{
			min = A[i];
		}
	}
	return min;
}

void Array::Reverse()
{
	int *B = new int[length];
	for(int i = length - 1, j = 0; i >= 0; i--, j++)
	{
		B[j] = A[i];
	}

	for(int i = 0; i < length; i++)
	{
		A[i] = B[i];
	}
}

void Array::Reverse2()
{
	for(int i = 0, j = length - 1; i < j; i++, j--)
	{
		this->Swap(&A[i], &A[j]);
	}
}

void Array::RotateLeft()
{
	int a = A[0];
	for(int i = 1; i < length; i++)
	{
		A[i - 1] = A[i];
	}
	A[length - 1] = a;
}

void Array::RotateRight()
{
	int a = A[length - 1];
	for(int i = length - 2; i >= 0 ; i--)
	{
		A[i + 1] = A[i];
	}
	A[0] = a;
}

void Array::InsertSorted(int x)
{
	if(length == size)
	{
		return;
	}
	int i = length - 1;
	while(i >= 0 && A[i] > x)
	{
		A[i + 1] = A[i];
		i--;
	}
	A[i + 1] = x;
	length++;
}

 bool Array::isSorted()
 {
	for(int i = 0; i < length - 1; i++)
	{
		if(A[i] > A[i + 1])
		{
			return false;
		}
	}
	return true;
 }

void Array::Rearrange()
{
	int i = 0, j = length - 1;
	while(i < j)
	{
		while(A[i] < 0)
		{
			i++;
		}
		while(A[j] > 0)
		{
			j--;
		}
		if(i < j)
		{
			this->Swap(&A[i], &A[j]);
		}
	}
}

Array* Array::Merge(Array *arr2)
{
	Array *arr3 = new Array[sizeof(Array)];
	int i=0,j=0,k=0;
	while(i < length && j < arr2->length)
	{
		if(A[i] < arr2->A[j])
			arr3->A[k++] = A[i++];
		else
			arr3->A[k++] = arr2->A[j++];
	}

	while(i < length)
		arr3->A[k++] = A[i++];

	while(j < arr2->length)
		arr3->A[k++] = arr2->A[j++];

	arr3->length = k;
	return arr3;
}

Array* Array::Union(Array *arr2)
{
	Array *arr3 = new Array[sizeof(Array)];
	int i=0,j=0,k=0;
	while(i < length && j < arr2->length)
	{
		if(A[i] < arr2->A[j])
			arr3->A[k++] = A[i++];
		else if(A[i] == arr2->A[j])
		{
			arr3->A[k++] = A[i++];
			j++;
		}
		else
			arr3->A[k++] = arr2->A[j++];
	}

	while(i < length)
		arr3->A[k++] = A[i++];

	while(j < arr2->length)
		arr3->A[k++] = arr2->A[j++];

	arr3->length = k;
	arr3->size = 10;
	return arr3;
}

Array* Array::Intersection(Array *arr2)
{
	Array *arr3 = new Array[sizeof(Array)];
	int i=0,j=0,k=0;
	while(i < length && j < arr2->length)
	{
		if(A[i] < arr2->A[j])
			i++;
		else if(A[i] == arr2->A[j])
		{
			arr3->A[k++] = A[i++];
			j++;
		}
		else
			j++;
	}

	arr3->length = k;
	arr2->size = 10;
	return arr3;
}

Array* Array::Difference(Array *arr2)
{
	Array *arr3 = new Array[sizeof(Array)];
	int i=0,j=0,k=0;
	while(i < length && j < arr2->length)
	{
		if(A[i] < arr2->A[j])
			arr3->A[k++] = A[i++];
		else if(A[i] == arr2->A[j])
		{
			i++;
			j++;
		}
		else
			j++;
	}

	while(i < length)
		arr3->A[k++] = A[i++];

	arr3->length = k;
	arr2->size = 10;
	return arr3;
}

int main()
{
	int choice = 0, index = 0, x = 0, size = 0;
	cout<<"\nEnter the No. of Elements :: ";
	cin>>size;
	Array arr1(size);
	while(1)
	{
		cout<<"\nMAIN MENU :: ";
		cout<<"\n1. Append";
		cout<<"\n2. Delete";
		cout<<"\n3. Search";
		cout<<"\n4. Sum";
		cout<<"\n5. Average";
		cout<<"\n6. Display";
		cout<<"\n7.Exit";
		cout<<"\n\nEnter Your Choice :: ";
		cin>>choice;
		switch(choice)
		{
			case 1 :
				cout<<"\nEnter the element :: ";
				cin>>x;
				arr1.append(x);
				break;
			case 2:
				cout<<"\nEnter the index :: ";
				cin>>index;
				cout<<"Deleted element is :: "<<arr1.Delete(index);
				break;
			case 3:
				cout<<"\nEnter the element to be searched :: ";
				cin>>x;
				cout<<"Found at :: "<<arr1.BinarySearch_loop(x);
				break;
			case 4:
				cout<<"\nSum of all the Elements is :: "<<arr1.Sum();
				break;
			case 5:
				cout<<"\nAverage of all the Elemnts is  :: "<<arr1.Avg();
				break;
			case 6:
				arr1.Display();
				break;
			case 7:
				return 0;
		}
	}
}

