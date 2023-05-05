#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int k)
{
	while(l<=r)
	{
		int mid = (l+r)/2;
		if(arr[mid] == k)
		{
			return mid;
		}
		if(arr[mid] < k)
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
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
