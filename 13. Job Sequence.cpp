#include<bits/stdc++.h>
using namespace std;

struct Job
{
	char id;
	int deadline;
	int profit;
};

bool compare(Job a,Job b)
{
    return a.deadline>b.deadline;
}

void JobSequencing(vector<Job> jobs)
{
	sort(jobs.begin(), jobs.end(), compare);
	
	int maxdeadline=0;
	for(int i=0;i<jobs.size();i++)
	{
		maxdeadline = max(maxdeadline,jobs[i].deadline);
	}
	
	vector<char> sequence(maxdeadline,'*');
	int totalProfit=0;
	
	for(int i=0;i<jobs.size();i++)
	{
		for(int j=jobs[i].deadline; j>=0; j--)
		{
			if(sequence[j] == '*')
			{
				sequence[j] = jobs[i].id;
				totalProfit += jobs[i].profit;
				break;
			}
		}
	}
	
	cout<<"Total Profit is : "<<totalProfit<<endl;
    cout<<"Job Sequence is : "<<endl;
    for(int i=0; i<sequence.size(); i++)
    {
        cout<<sequence[i]<<" -> ";
    }
    cout<<endl;
}

int main()
{
	vector<Job> jobs;
	Job job1 = {'A', 2, 100};
    Job job2 = {'B', 1, 19};
    Job job3 = {'C', 2, 27};
    Job job4 = {'D', 1, 25};
    Job job5 = {'E', 3, 15};
    jobs.push_back(job1);
    jobs.push_back(job2);
    jobs.push_back(job3);
    jobs.push_back(job4);
    jobs.push_back(job5);
    
    JobSequencing(jobs);
}
