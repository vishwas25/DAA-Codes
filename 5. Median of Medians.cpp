#include<bits/stdc++.h>
using namespace std;

int findMedian(vector<int>& arr, int l, int r)
{
	if(r-l <= 5)
	{
		sort(arr.begin()+l, arr.begin()+r);
		return arr[(l+r)/2];
	}
	
	vector<int> medians;
	for(int i=l;i<=r;i+=5)
	{
		int subEnd = min(i+4, r);
		sort(arr.begin()+i, arr.begin()+subEnd);
		medians.push_back(arr[(i+subEnd)/2]);
	}
	int medianofMedians = findMedian(medians, 0, medians.size()-1);
	return medianofMedians;
}

int partition(vector<int>& arr, int l, int r, int pivot)
{
	int pivotIdx = l;
	for(int i=l;i<=r;i++)
	{
		if(arr[i]==pivot)
		{
			pivotIdx = i;
			break;
		}
	} 
	swap(arr[pivotIdx], arr[r]);
	
    int j=l-1;
    for(int i=l;i<r;i++)
    {
        if(arr[i] < arr[r])
        {
            j++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j+1], arr[r]);
    return j+1;
}

void quickSort(vector<int>& arr, int l, int r)
{
    if(l<r)
    {
    	int pivot = findMedian(arr, l, r);
        int pi = partition(arr, l, r, pivot);
        quickSort(arr, l, pi-1);
        quickSort(arr, pi+1, r);
    }
}

int main()
{
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    int l=0,r=n-1;
    
    quickSort(arr, l, r);
    
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}




// if asked to find median element
/*
#include<bits/stdc++.h>
using namespace std;

int findMedian(vector<int>& arr, int l, int r)
{
    if(r-l <= 5)
    {
        sort(arr.begin()+l, arr.begin()+r+1);
        return arr[l + (r-l+1)/2];
    }
    
    vector<int> medians;
    for(int i=l;i<=r;i+=5)
    {
        int subEnd = min(i+4, r);
        sort(arr.begin()+i, arr.begin()+subEnd+1);
        medians.push_back(arr[i + (subEnd-i+1)/2]);
    }
    int medianofMedians = findMedian(medians, 0, medians.size()-1);
    return medianofMedians;
}

int partition(vector<int>& arr, int l, int r, int pivot)
{
    int pivotIdx = l;
    for(int i=l;i<=r;i++)
    {
        if(arr[i]==pivot)
        {
            pivotIdx = i;
            break;
        }
    } 
    swap(arr[pivotIdx], arr[r]);
    
    int j=l-1;
    for(int i=l;i<r;i++)
    {
        if(arr[i] < arr[r])
        {
            j++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j+1], arr[r]);
    return j+1;
}

int main()
{
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    int l=0,r=n-1;
    
    int medianIdx = (n+1)/2 - 1;
    int median = findMedian(arr, l, r);
    
    cout << "Median element: " << median << endl;
}
*/
