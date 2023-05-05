#include<bits/stdc++.h>
using namespace std;

pair<int,int> findMinMax(int arr[], int l, int r)
{
	pair<int,int> result;
	pair<int,int> left_result;
	pair<int,int> right_result;
	
	int mid;
	
	if(l==r)
	{
		result.first = arr[l];
		result.second = arr[l];
		return result;
	}
	if(r == l+1)
	{
		if(arr[l] > arr[r])
		{
			result.first = arr[l];
			result.second = arr[r];
		}
		else
		{
			result.first = arr[r];
			result.second = arr[l];
		}
		return result;
	}
	
	mid=(l+r)/2;
	
	left_result = findMinMax(arr, l, mid);
	right_result = findMinMax(arr, mid+1, r);
	
	if(left_result.first > right_result.first)
	{
		result.first = left_result.first;
	}
	else
	{
		result.first = right_result.first;
	}
	if (left_result.second < right_result.second)
	{
		result.second = left_result.second;
	}
	else
	{
		result.second = right_result.second;
	}
	return result;
}

int main()
{
	int i,num,arr[30];
	cout<<"Enter the size of array : ";
	cin>>num;
	cout<<"\nEnter the numbers : ";
	for(int i=0;i<num;i++)
	{
		cin>>arr[i];
	}
	pair<int,int> result = findMinMax(arr, 0, num-1);
	
	cout << "\nMinimum element is: " << result.second << endl;
	cout << "\nMaximum element is: " << result.first << endl;
	return 0;
}
