#include<bits/stdc++.h>
using namespace std;

sortCol(const vector<int>& v1, const vector<int>& v2)
{
	return v1[1] < v2[1];
}

int main()
{
	int n,ip,end;
	cout<<"Enter number of persons : ";
	cin>>n;
	
	vector<vector<int> > v;
	cout<<"Enter the start and end time : ";
	for(int i=0;i<n;i++)
	{
		vector<int> v1;
		for(int j=0;j<2;j++)
		{
			cin>>ip;
			v1.push_back(ip);
		}
		v.push_back(v1);
	}
	
	sort(v.begin(), v.end(), sortCol);
	
	int take = 1;
	end = v[0][1];
	for(int i=1;i<n;i++)
	{
		if(v[i][0] >= end)
		{
			take++;
			end = v[i][1];
		}
	}
	
	cout<<"\ Maximum number of activities: "<<take<<endl;
	return 0;
}
