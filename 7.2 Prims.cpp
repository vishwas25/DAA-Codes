#include<bits/stdc++.h>
using namespace std;

#define INF 9999
#define V 5
int G[V][V];

int main()
{
	int no_of_edges, cost_path, V1;
	int selected[V];
	
	memset(selected ,false, sizeof(selected));
	
	cout<<"Enter total number of vertices : ";
	cin>>V1;
	cout<<"Enter adjency matrix : ";
	for(int i=0;i<V1;i++)
	{
		for(int j=0;j<V1;j++)
		{
			cin>>G[i][j];
		}
	}
	
	selected[0]=true;
	int x,y;
	int i=0,j=0;
	
	cout<<"Edge "<<" : "<<"Weight"<<endl;
	while(no_of_edges < V1-1)
	{
		int min=INF;
		x=0,y=0;
		
		for(i=0;i<V1;i++)
		{
			if(selected[i])
			{
				for(j=0;j<V1;j++)
				{
					if(!selected[j] and G[i][j])
					{
						if(min > G[i][j])
						{
							min = G[i][j];
							x=i;
							y=j;
						}
					}
				}
			}
		}
		cout<<x<<" - "<<y<<" : "<<G[x][y];
		cost_path += G[x][y];
		selected[y]=true;
		no_of_edges++;
	}
	
	cout<<"Minimum cost : "<<cost_path;
}

/*
Enter total number of vertices :
5

Enter the adjacent matrix for cost : 1 5 2 9 4
7 0 9 1 4
8 9 0 5 6
0 1 5 0 3
0 4 6 3 0
Edge : Weight
0 - 2 : 2
0 - 4 : 4
4 - 3 : 3
3 - 1 : 1

Minimum cost of path : 10
*/
