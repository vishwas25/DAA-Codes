#include <iostream>
#include <vector>
using namespace std;


int GetMaxProfit(vector<int> weights,vector<int> values,int capacity)
{
    vector<vector<int> > dp(weights.size()+1,vector<int> (capacity+1,0));

    for(int i=1; i<=weights.size(); i++)
    {
        for(int j=1; j<=capacity; j++)
        {
            if(weights[i-1]<=j)
            {
                dp[i][j] = max(dp[i-1][j],values[i-1]+dp[i-1][j-weights[i-1]]);
            }else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[weights.size()][capacity];
}


int main()
{
    int capacity;
    cout<<"Enter the capacity : "<<endl;
    cin>>capacity;

    int n;
    cout<<"Enter the number of items : "<<endl;
    cin>>n;

    vector<int> weights(n);
    vector<int> values(n);

    cout<<"Enter the weights and Profits of Items : "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"Item "<<i+1<<" : ";
        cin>>weights[i]>>values[i];
    }

    int maxProfit = GetMaxProfit(weights,values,capacity);
    cout<<maxProfit<<endl;
}


/*
Enter the capacity :
5
Enter the number of items :
4
Enter the weights and Profits of Items :
Item 1 : 2
12
Item 2 : 1 10
Item 3 : 3 20
Item 4 : 2 15
37
*/
