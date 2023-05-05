#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
	int n1=mid-l+1;
	int n2=r-mid;
	
	int a[n1];
	int b[n2];
	
	for(int i=0;i<n1;i++)
	{
		a[i] = arr[l+i];
	}
	for(int i=0;i<n2;i++)
	{
		b[i] = arr[mid+i+1];
	}
	
	int i=0,j=0,k=l;
	
	while(i<n1 && j<n2)
	{
		if(a[i] < b[j])
		{
			arr[l] = a[i];
			l++;i++;
		}
		else
		{
			arr[l] = b[j];
			l++;j++;
		}
	}
	
	while(i<n1)
	{
		arr[l] = a[i];
		l++;i++;
	}
	while(j<n2)
	{
		arr[l] = b[j];
		l++;j++;
	}
}

void mergeSort(int arr[], int l, int r)
{
	if(l<r)
	{
		int mid = (l+r)/2;
		
		mergeSort(arr, l, mid);
		mergeSort(arr, mid+1, r);
		
		merge(arr, l, mid, r);
	}
}

int main()
{
	int n;
	cout<<"Enter the size of array : ";
	cin>>n;
	int arr[n-1];
	cout<<"Enter the elements : ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	int l=0,r=n-1;
	mergeSort(arr, l, r);
	
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
