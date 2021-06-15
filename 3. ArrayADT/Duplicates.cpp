#include<iostream>
using namespace std;

void Duplicates(int arr[], int n)
{
	int lastDuplicate = 0;
	cout<<"Duplicate Elements are :: ";
	for(int i = 0; i < n ; i++)
	{
		if(arr[i] == arr[i + 1] && arr[i] != lastDuplicate)
		{
			cout<<arr[i]<<" ";
			lastDuplicate = arr[i];
		}
	}
}

void DuplicatesCounter(int arr[], int n)
{
	int j = 0;
	for(int i = 0; i < n - 1; i++)
	{
		if(arr[i] = arr[i + 1])
		{
			j = i + 1;
			while(arr[i] == arr[j + 1])
			{
				j++;
			}
			cout<<arr[i]<<" - "<<j - i<<endl;
			i = j - 1;
		}
	}
}

int Max(int arr[], int n)
{
	int max = 0;
	for(int i = 0; i < n; i++)
	{
		if(max < arr[i])
		{
			max = arr[i];
		}
	}
	return max;
}

void DuplicatesCounter2(int arr[], int n)
{
	int h = Max(arr, n);
	int hash[h + 1] = {0};
	for(int i = 0; i < n; i++)
	{
		hash[arr[i]]++;
	}
	for(int i = 0; i <= h ; i++)
	{
		if(hash[i] > 1)
		{
			cout<<i<<" - "<<hash[i]<<endl;
		}
	}
}

void DuplicatesCounterUnsorted(int arr[], int n)
{
	for(int i = 0; i < n - 1; i++)
	{
		int ctr = 1;
		if(arr[i] != -1)
			for(int j = i + 1; j < n; j++)
			{
				if(arr[i] == arr[j])
				{
					ctr++;
					arr[j] = -1;
				}
			}
		if(ctr > 1)
			cout<<arr[i]<<" - "<<ctr<<endl;
	}
}
void DuplicatesCounterUnsorted2(int arr[], int n)
{
	int h = Max(arr, n);
	int hash[h + 1] = {0};
	for(int i = 0; i < n; i++)
	{
		hash[arr[i]]++;
	}
	for(int i = 0; i <= h ; i++)
	{
		if(hash[i] > 1)
		{
			cout<<i<<" - "<<hash[i]<<endl;
		}
	}
}
int main()
{
	int arr[10] = {8,3,6,4,6,5,6,8,2,7};
	DuplicatesCounterUnsorted2(arr,10);
	return 0;
}

