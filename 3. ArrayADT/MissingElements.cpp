#include<iostream>
using namespace std;

void MissingSingleSorted(int arr[], int n)
{
	int sum = 0;
	int a = arr[n - 1];
	int s = (a * (a + 1)) / 2;
	for(int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	cout<<"Missing Element is :: "<<s - sum;
}

void MissingSingleSorted2(int arr[], int n)
{
	int diff = arr[0];
	int i = 0;
	for(i = 0; i < n ;i++)
	{
		if(arr[i] - i != diff)
		{
			break;
		}
	}
	cout<<"Misssing Element is :: "<<diff + i;
}

void MissingMultipleSorted(int arr[], int n)
{
	int diff = arr[0];
	cout<<"Missing Elements are :: ";
	for(int i = 0; i < n ; i++)
	{
		if(arr[i] - i != diff)
		{
			while(diff < arr[i] - (i))
			{
				cout<<i + diff<<" ";
				diff++;
			}
		}
	}
}

int Max(int arr[], int n)
{
	int max = arr[0];
	for(int i = 0; i < n; i++)
	{
		if(arr[i] > max)
			max = arr[i];
	}
	return max;
}

void MissingMultipleUnsorted(int arr[], int n)
{
	int h = Max(arr,n);
	int hash[h] = {0};
	for(int i = 0; i < n; i++)
	{
		hash[arr[i]]++;
	}
	cout<<"Missing elements are :: ";
	for(int i = 1; i <= h ; i++)
	{
		if(hash[i] == 0)
		{
			cout<<i<<" ";
		}
	}
}

int main()
{
	int arr[10] = {16,12,3,4,15,9,10,13,6,2};
	MissingMultipleUnsorted(arr,10);
	return 0;
}

