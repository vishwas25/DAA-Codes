#include<bits/stdc++.h>
using namespace std;

int coinchange(int coins[],int amount, int n)
{
	int x = n;
	int y = amount;
	
	int arr[x+1][y+1];
	
	
	for(int i=0; i<=x; i++)
	{
		for(int j=0; j<=y; j++)
		{
			if(j==0 || i==0)
			{
				arr[i][j] = 0;
			}
			else if(i==1)
			{
				arr[i][j] = j/coins[i];
			}
			else if(coins[i] > j)
			{
				arr[i][j] = arr[i-1][j];
			}
			else
			{
				arr[i][j] = min(arr[i-1][j], 1+arr[i][j-coins[i]]);
			}
		}
	}
	
	//Printing coins
	int j=amount,i=n;
    queue<int> q;
    cout<<"\n Coins are : "<<endl;
    while (j)
    {
        if(arr[i][j]!=arr[i-1][j])
        {
            cout<<coins[i]<<"+";
            j-=coins[i];
        }
        else
            i--;
    }
	
	return arr[x][y];
}

int main()
{
	int amount,n;
    cout<<"\nEnter total amount: ";
    cin>>amount;
    cout<<"\nEnter the total number of coins: ";
    cin>>n;
    int coins[n+1];
    cout<<"\nEnter value of each coin: "<<endl;
    coins[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>coins[i];
    }
    sort(&coins[0],&coins[n+1]);
		
	int val = coinchange(coins,amount,n);
	cout<<"\n\nTotal number of coins required are : "<<val;
    
    return 0;
}
