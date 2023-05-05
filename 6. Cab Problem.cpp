#include<bits/stdc++.h>
using namespace std;

bool sortCol(const vector<int>& v1, const vector<int>& v2)
{
	return v1[1] < v2[1];
}

int main()
{
	int n,ip,end;
	cout<<"Enter number of persons : ";
	cin>>n;
	
	vector<vector<int> > v;
	cout<<"Enter the start and end time of persons : ";
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
	
	set<int> taken;
	int cabs = 1;
	
	while(taken.size() < n)
	{
		cout << "\nCab " << cabs<<" Will have these many Activities : " << endl;
		end = -1;
		cabs++;
		for(int i=0;i<n;i++)
		{
			if(taken.find(i) != taken.end())
			{
				continue;
			}
			if(v[i][0] < end)
			{
				continue;
			}
			taken.insert(i);
			cout << v[i][0] << " " << v[i][1] << endl;
			end = v[i][1];
		}
	}
	
	cout<<"\nMinimum number of cabs required : "<<cabs-1<<endl;
	return 0;
}
