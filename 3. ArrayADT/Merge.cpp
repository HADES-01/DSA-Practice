#include<iostream>
using namespace std;

struct Array
{
	int A[10];
	int size;
	int length;
};

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

void Display(struct Array arr)
{
	cout<<"\nThe elements are :: ";
	for(int i = 0; i < arr.length; i++)
	{
		cout<<arr.A[i]<<" ";
	}
}

int main(){
	struct Array arr1 = {{2,6,10,15,25}, 10, 5};
	struct Array arr2 = {{3,4,7,18,20}, 10, 5};
	struct Array *arr3;
	arr3 = Merge(&arr1, &arr2);
	Display(*arr3);
	return 0;
}


