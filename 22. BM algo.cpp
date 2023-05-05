#include<iostream>
#include<bits/stdc++.h>
using namespace std; //dict.count()

int main()
{
    map<char,int> dict;
    string s,p;
    
    cout<<"\nEnter the string: ";
    cin>>s;
    cout<<"\nEnter the pattern: ";
    cin>>p;
    
    int pl=p.length();
	int sl=s.length();
    
    for(int i=0;i<pl;i++)
    {
        dict.emplace(p[i],max(1,(pl-i-1)));
    }
    
    dict.emplace('*',pl);
    dict[p[pl-1]]=pl;
    
    vector<int> ind;
    int j=0;
    
    for(int i=0;i<sl;i++)
    {
        if(s[i]!=p[j] && dict[p[j]])
        {
        	j-=dict[p[j]];
        	j=0;
		}

        else if(j==pl-1)
        {
            ind.push_back(i-j);
            j=0;
        }
        j++;
    }
    
    cout<<"\nThe bad character table looks like: "<<endl;
    for(auto i:dict)    //for(int i=0;i<dict.count();i++)
    {
    	cout<<i.first<<" "; //dict[i]
	}
    cout<<endl;
    
    for(auto i:dict)
    {
    	cout<<i.second<<" ";	
	}
    cout<<endl;
    
    cout<<"\nThe pattern is found at index position: "<<endl;
    for(auto i:ind)
    {
    	cout<<i<<" ";	
	}
    cout<<endl;
    
    return 0;
}

/*
Enter the string: thisisatext

Enter the pattern: text

The bad character table looks like:
* e t x
4 2 4 1

The pattern is found at index position:
7

--------------------------------
Process exited after 12.92 seconds with return value 0
Press any key to continue . . .
*/


// if above not working
/*
#include <bits/stdc++.h>
using namespace std;
# define NO_OF_CHARS 256

void badCharHeuristic( string str, int size, int badchar[NO_OF_CHARS])
{
	int i;

	for (i = 0; i < NO_OF_CHARS; i++)
		badchar[i] = -1;

	for (i = 0; i < size; i++)
		badchar[(int) str[i]] = i;
}

void search( string txt, string pat)
{
	int m = pat.size();
	int n = txt.size();

	int badchar[NO_OF_CHARS];

	badCharHeuristic(pat, m, badchar);

	int s = 0; 
	while(s <= (n - m))
	{
		int j = m - 1;

		while(j >= 0 && pat[j] == txt[s + j])
			j--;

		if (j < 0)
		{
			cout << "\npattern occurs at shift = " << s << endl;

			s += (s + m < n)? m-badchar[txt[s + m]] : 1;

		}

		else
			s += max(1, j - badchar[txt[s + j]]);
	}
}

int main()
{
	string txt;
	string pat;
	cout<<"Enter the Text : ";
	cin>>txt;
	cout<<"\nEnter the pattern : ";
	cin>>pat;
	search(txt, pat);
	return 0;
}
*/
