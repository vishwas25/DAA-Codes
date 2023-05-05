#include<bits/stdc++.h>
using namespace std;

int main()
{
	int v,d;
	
	cout<<"Enter Value : ";
	cin>>v;
	cout<<"Enter how many denominations are available : ";
	cin>>d;
	int coins[d];
	cout<<"Enter the denomination : ";
	for(int i=0; i<d; i++)
	{
		cin>>coins[i];
	}
	
	sort(coins, coins+d, greater<int>());
	
	int x = v;
	int j=0;
	
	vector<int> sol;
	
	for(int i=0; i<d; i++)
	{
		while(x>=coins[i])
		{
			x = x - coins[i];
			sol.push_back(coins[i]);
			j++;
		}
		if(x==0)
		{
			break;
		}
	}
	
	cout<<"\n\nNo. of selected coins are : "<<j<<endl;
	cout<<"Coins are ";
	for(int i=0; i<sol.size(); i++)
	{
		cout<<sol[i]<<" ";
	}
}
