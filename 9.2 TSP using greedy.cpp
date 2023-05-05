#include<bits/stdc++.h>
using namespace std;

int arr[10][10], completed[10],n,cost=0;

int least(int c)
{
	int nc=999, min=999, kmin;
	
	for(int i=0;i<n;i++)
	{
		if((arr[c][i] != 0) and (completed[i]==0))
		{
			if(arr[c][i] + arr[i][c] < min)
			{
				min = arr[i][0] + arr[c][i];
				kmin = arr[c][i];
				nc = i;
			}
		}
	}
	if(min != 999)
	{
		cost += kmin;
	}
	return nc;
}

void mincost(int city)
{
	int i, ncity;
	completed[city]=1;
	
	cout<<city+1<<"-->";
	ncity = least(city);
	
	if(ncity == 999)
	{
		ncity=0;
		cout<<ncity+1;
		cost += arr[city][ncity];
		return;
	}
	mincost(ncity);
}

int main()
{
	cout<<"Enter the number of cities : ";
	cin>>n;
	
	cout<<"Enter the Cost Matrix \n ";
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter elements of row "<<i+1<<" - ";
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
		completed[i]=0;
	}
	
	mincost(0);
	
	cout<<"\nMinimun cost of path is : "<<cost;
}


/*
Enter the number of cities: 3

Enter the Cost Matrix

Enter Elements of Row: 1
0 2 3

Enter Elements of Row: 2
2 0 4

Enter Elements of Row: 3
3 4 0


The cost list is:
        0       2       3
        2       0       4
        3       4       0
		1--->2--->3--->1
        Minimum cost of path is: 9
*/
