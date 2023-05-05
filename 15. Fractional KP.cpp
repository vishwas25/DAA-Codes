#include<bits/stdc++.h>
using namespace std;
int ind=1;

class item
{
	public:
		int p,w;
		int id=ind++;
		float pDw;
		void calc_pDw()
		{
			pDw=p/w;
		}
};

bool sortCol(const item &v1,const item &v2)
{
	return v1.pDw > v2.pDw;
}
      
int main()
{
	int n;
	cout<<"Enter the no. of items : ";
	cin>>n;
	item arr[n];
	int p,w;
	cout<<"\nEnter profit and weight for each item : "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>p>>w;
		arr[i].p=p;
		arr[i].w=w;
		arr[i].calc_pDw();
	}
	
	int wt=0,cap,rem;
	float pt=0;
	cout<<"\nEnter the capacity : ";
	cin>>cap;
	
	sort(arr, arr+n-1, sortCol);
	
	for(int i=0;i<n and wt<cap;i++)
	{
		rem = cap-wt;
		if(arr[i].w <= rem)
		{
			pt += arr[i].p;
			cout<<arr[i].id<<" included totally"<<endl;
			wt += arr[i].w;
		}
		else
		{
			pt += rem*arr[i].pDw;
			cout<<arr[i].id<<" included partially"<<endl;
			wt += rem;
		}
	}
	cout<<"\nThe maximum profit is "<<pt<<endl;
    return 0;
}
