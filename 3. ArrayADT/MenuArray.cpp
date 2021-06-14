#include<iostream>
#include<process.h>
using namespace std;

struct Array
{
	int *A;
	int size;
	int length;
};

void Display(struct Array arr)
{
	cout<<"\nThe elements are :: ";
	for(int i = 0; i < arr.length; i++)
	{
		cout<<arr.A[i]<<" ";
	}
}

void Append(struct Array *arr, int x)
{
	if(arr->length < arr->size)
	{
		arr->A[arr->length++] = x;
	}
}

void Insert(struct Array *arr, int index, int x)
{
	if(index >= 0 && index <= arr->length)
	{
		for(int i = arr->length; i > index; i--)
			arr->A[i] = arr->A[i - 1];
		arr->A[index] = x;
		arr->length++;
	}
	else
	{
		cout<<"\nEnter a Valid Index!!!!";
	}
}

int Delete(struct Array *arr, int index)
{
	if(index < arr->length)
	{
		int x = arr->A[index];
		for(int i = index; i < arr->length - 1; i++)
		{
			arr->A[i] = arr->A[i + 1];
		}
		arr->length--;
		return x;
	}
	else
	{
		cout<<"\n Enter a Valid Index!!!";
		return 0;
	}
}

void Swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int LinearSearch(struct Array *arr, int key)
{
	for(int i = 0; i < arr->length; i++)
	{
		if(arr->A[i] == key)
		{
//			Swap(&arr->A[i], &arr->A[i-1]);  //Transposition
//			return i - 1;
//			Swap(&arr->A[i], &arr->A[0]);  //Move to Head
//			return 0;
			return i;  //Normal Linear Search
		}
	}
	return -1;
}

int BinarySearch_loop(struct Array arr, int key)
{
	int l, h, mid;
	l = 0; h = arr.length - 1;
	while(l < h)
	{
		mid = (l + h) / 2;
		if(key == arr.A[mid])
			return mid;
		else if(key < arr.A[mid])
			h = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}

int BinarySearch_recur(int arr[],int l,int h,int key)
{
	int mid = 0;
	if(l <= h)
	{
		mid = (l + h) / 2;
		if(arr[mid] == key)
			return mid;
		else if(arr[mid] > key)
			return BinarySearch_recur(arr, l, mid - 1, key);
		else
			return BinarySearch_recur(arr, mid + 1, h, key);
	}
	return -1;
}

int Get(struct Array arr, int index)
{
	if(index >= 0 && index < arr.length)
	{
		return arr.A[index];
	}
}

void Set(struct Array *arr, int index, int x)
{
	if(index >= 0 && index < arr->length)
	{
		arr->A[index] = x;
	}
}

int Sum(struct Array arr)
{
	int sum = 0;
	for(int i = 0; i < arr.length; i++)
	{
		sum += arr.A[i];
	}
	return sum;
}

float Avg(struct Array arr)
{
	return float(Sum(arr) / arr.length);
}

int Max(struct Array arr)
{
	int max = arr.A[0];
	for(int i = 0; i < arr.length; i++)
	{
		if(max < arr.A[i])
		{
			max = arr.A[i];
		}
	}
	return max;
}

int Min(struct Array arr)
{
	int min = arr.A[0];
	for(int i = 0; i < arr.length; i++)
	{
		if(min > arr.A[i])
		{
			min = arr.A[i];
		}
	}
	return min;
}

void Reverse(struct Array *arr)
{
	int *B = new int[arr->length];
	for(int i = arr->length - 1, j = 0; i >= 0; i--, j++)
	{
		B[j] = arr->A[i];
	}

	for(int i = 0; i < arr->length; i++)
	{
		arr->A[i] = B[i];
	}
}

void Reverse2(struct Array *arr)
{
	for(int i = 0, j = arr->length - 1; i < j; i++, j--)
	{
		Swap(&arr->A[i], &arr->A[j]);
	}
}

void RotateLeft(struct Array *arr)
{
	int a = arr->A[0];
	for(int i = 1; i < arr->length; i++)
	{
		arr->A[i - 1] = arr->A[i];
	}
	arr->A[arr->length - 1] = a;
}

void RotateRight(struct Array *arr)
{
	int a = arr->A[arr->length - 1];
	for(int i = arr->length - 2; i >= 0 ; i--)
	{
		arr->A[i + 1] = arr->A[i];
	}
	arr->A[0] = a;
}

void InsertSorted(struct Array *arr, int x)
{
	if(arr->length == arr->size)
	{
		return;
	}
	int i = arr->length - 1;
	while(i >= 0 && arr->A[i] > x)
	{
		arr->A[i + 1] = arr->A[i];
		i--;
	}
	arr->A[i + 1] = x;
	arr->length++;
}

 bool isSorted(struct Array arr)
 {
	for(int i = 0; i < arr.length - 1; i++)
	{
		if(arr.A[i] > arr.A[i + 1])
		{
			return false;
		}
	}
	return true;
 }

void Rearrange(struct Array *arr)
{
	int i = 0, j = arr->length - 1;
	while(i < j)
	{
		while(arr->A[i] < 0)
		{
			i++;
		}
		while(arr->A[j] > 0)
		{
			j--;
		}
		if(i < j)
		{
			Swap(&arr->A[i], &arr->A[j]);
		}
	}
}

struct Array* Merge(struct Array *arr1, struct Array *arr2)
{
	struct Array *arr3 = new struct Array[sizeof(struct Array)];
	int i=0,j=0,k=0;
	while(i < arr1->length && j < arr2->length)
	{
		if(arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++];
		else
			arr3->A[k++] = arr2->A[j++];
	}

	while(i < arr1->length)
		arr3->A[k++] = arr1->A[i++];

	while(j < arr2->length)
		arr3->A[k++] = arr1->A[j++];

	arr3->length = k;
	return arr3;
}

struct Array* Union(struct Array *arr1, struct Array *arr2)
{
	struct Array *arr3 = new struct Array[sizeof(struct Array)];
	int i=0,j=0,k=0;
	while(i < arr1->length && j < arr2->length)
	{
		if(arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++];
		else if(arr1->A[i] == arr2->A[j])
		{
			arr3->A[k++] = arr1->A[i++];
			j++;
		}
		else
			arr3->A[k++] = arr2->A[j++];
	}

	while(i < arr1->length)
		arr3->A[k++] = arr1->A[i++];

	while(j < arr2->length)
		arr3->A[k++] = arr1->A[j++];

	arr3->length = k;
	arr2->size = 10;
	return arr3;
}

struct Array* Intersection(struct Array *arr1, struct Array *arr2)
{
	struct Array *arr3 = new struct Array[sizeof(struct Array)];
	int i=0,j=0,k=0;
	while(i < arr1->length && j < arr2->length)
	{
		if(arr1->A[i] < arr2->A[j])
			i++;
		else if(arr1->A[i] == arr2->A[j])
		{
			arr3->A[k++] = arr1->A[i++];
			j++;
		}
		else
			j++;
	}

	arr3->length = k;
	arr2->size = 10;
	return arr3;
}

struct Array* Difference(struct Array *arr1, struct Array *arr2)
{
	struct Array *arr3 = new struct Array[sizeof(struct Array)];
	int i=0,j=0,k=0;
	while(i < arr1->length && j < arr2->length)
	{
		if(arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++];
		else if(arr1->A[i] == arr2->A[j])
		{
			i++;
			j++;
		}
		else
			j++;
	}

	while(i < arr1->length)
		arr3->A[k++] = arr1->A[i++];

	arr3->length = k;
	arr2->size = 10;
	return arr3;
}


int main()
{
	int choice = 0, index = 0, x = 0;
	struct Array arr1;
	cout<<"\nEnter the No. of Elements :: ";
	cin>>arr1.size;
	arr1.A = new int[arr1.size];
	arr1.length = arr1.size;
	cout<<"Enter the Elements :: ";
	for(int i = 0; i < arr1.size; i++)
	{
		cin>>arr1.A[i];
	}
	
	while(1)
	{
		cout<<"\nMAIN MENU :: ";
		cout<<"\n1. Insert";
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
				cout<<"Enter the index :: ";
				cin>>index;
				Insert(&arr1, index,x);
				break;
			case 2:
				cout<<"\nEnter the index :: ";
				cin>>index;
				cout<<"Deleted element is :: "<<Delete(&arr1, index);
				break;
			case 3:
				cout<<"\nEnter the element to be searched :: ";
				cin>>x;
				cout<<"Found at :: "<<BinarySearch_loop(arr1, x);
				break;
			case 4:
				cout<<"\nSum of all the Elements is :: "<<Sum(arr1);
				break;
			case 5:
				cout<<"\nAverage of all the Elemnts is  :: "<<Avg(arr1);
				break;
			case 6:
				Display(arr1);
				break;
			case 7:
				return 0;
		}
	}
	return 0;
}

