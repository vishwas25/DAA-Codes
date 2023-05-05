#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int r)
{
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

void quickSort(int arr[], int l, int r)
{
    if(l<r)
    {
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi-1);
        quickSort(arr, pi+1, r);
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
    
    quickSort(arr, l, r);
    
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
