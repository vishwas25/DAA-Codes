#include<bits/stdc++.h>
using namespace std;

int getRandom(int l, int r)
{
	srand(time(NULL));
	return (l+ (rand()%(r-l+1)));
}

int binarySearch(int arr[], int l, int r, int k)
{
	while(l<=r)
	{
		int m = getRandom(l,r);
		if(arr[m] == k)
		{
			return m;
		}
		if(arr[m] < k)
		{
			l = m+1;
		}
		else
		{
			r = m-1;
		}
	}
	return -1;
}

int main()
{
	int size;
	cout<<"Enter the size of array : ";
	cin>>size;
	
	int arr[size-1];
	
	cout<<"Enter the elements : ";
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	
	int x;
	cout<<"Enter the element to be searched : ";
	cin>>x;
	
	int result = binarySearch(arr, 0, size-1, x);
	
	if(result != -1)
	{
		cout<<"Element is present at index : "<<result;
	}
	else
	{
		cout<<"Element is not present.";
	}
}
