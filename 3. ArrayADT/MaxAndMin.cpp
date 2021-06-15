#include<iostream>
using namespace std;

void MaxAndMin(int arr[], int n)
{
	int max, min;
	max = min = arr[0];
	for(int i = 0; i < n; i++)
	{
		if(min > arr[i])
		{
			min = arr[i];
		}
		else if(max < arr[i])
		{
			max = arr[i];
		}
	}
	cout<<"MAX :: "<<max;
	cout<<endl<<"MIN :: "<<min;
}

int main()
{
	int arr[10] = {5,8,3,9,6,2,10,7,-1,4};
	MaxAndMin(arr,10);
	return 0;
}

