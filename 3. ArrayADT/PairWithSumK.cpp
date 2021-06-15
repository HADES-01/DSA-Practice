#include<iostream>
using namespace std;

void PairsWithSum(int arr[], int n, int K)
{
	for(int i = 0; i < n; i++)
	{
		if(arr[i] != -1)
			for(int j = i + 1; j < n; j++)
			{
				if(arr[i] + arr[j] == K)
				{
					cout<<arr[i]<<" + "<<arr[j]<<" = "<<K<<endl;
					arr[j] = -1;
				}
			}
	}
}

int max(int arr[], int n)
{
	int max = arr[0];
	for(int i = 0; i < n; i++)
	{
		if(max < arr[i])
			max = arr[i];
	}
	return max;
}

void PairsWithSum2(int arr[], int n, int k)
{
	int h = max(arr, n);
	int hash[h + 1] = {0};
	for(int i = 0; i < n; i++)
	{
		if(hash[k - arr[i]] != 0 && (k - arr[i]) > 0)
			cout<<arr[i]<<" + "<<k - arr[i]<<endl;
		hash[arr[i]]++;
	}
}

void PairsWithSumSorted(int arr[], int n, int k)
{
	int i = 0, j = n - 1;
	while(i < j)
	{
		if(arr[i] + arr[j] > k)
			j--;
		else if(arr[i] + arr[j] < k)
			i++;
		else
		{
			cout<<arr[i]<<" + "<<arr[j]<<endl;
			i++;
			j--;
		}
	}
}

int main()
{
	int arr[10] = {1,3,4,5,6,8,9,10,12,14};
	int k = 10;
	PairsWithSumSorted(arr,10,k);
	return 0;
}

