#include<bits/stdc++.h>
#include <string.h>
#include <iostream>
using namespace std;

#define d 10

void rabinKarp(string pattern, string text, int q) 
{
  int m = pattern.length();
  int n = text.length();
  int i, j;
  int p = 0;
  int t = 0;
  int h = 1;
  int sp_count=0;

  for (i = 0; i < m - 1; i++)
  {
	h = (h * d) % q;
  }

  for (i = 0; i < m; i++) 
  {
    p = (d * p + pattern[i]) % q;
    t = (d * t + text[i]) % q;
  }

  cout<<endl<<"\nHash value of pattern '"<<pattern<<"' is: "<<p<<endl;

  // Find the match
  for (i = 0; i <= n - m; i++) 
  {
    cout<<endl<<"Step "<<(i+1);
    cout<<endl<<"T"<<i<<" = "<<t<<endl;
    if (p == t) 
	{
    
        cout<<"p("<<p<<") = t("<<t<<")"<<"\t Hash values matched"<<endl;
        for (j = 0; j < m; j++) 
		{
            if (text[i + j] != pattern[j])
            {
                cout<<"Spurious hit!!"<<endl;
                sp_count++;
                break;
            }
      	}

      if (j == m)
        {
            cout << "\nPattern is found at position: " << i + 1 << endl;
            break;
        }
    }

    cout<<"p("<<p<<") != t("<<t<<")"<<endl;

    if (i < n - m) 
	{
      t = (d * (t - text[i] * h) + text[i + m]) % q;

      if (t < 0)
        t = (t + q);
    }
  }
  cout<<"\nSpurious hit count: "<<sp_count<<endl;
}

int main() 
{
  string text,pattern;
  
  cout<<"\nEnter text: ";
  cin>>text;
  
  cout<<"\nEnter Pattern: ";
  cin>>pattern;
  
  int q = 13;
// 	 "2359023141526739921";
// 	 "31415";
  cout<<endl<<"\n\t**********Rabin Karp Algorithm**********"<<endl;
  cout<<"Modulo(q) : "<<q<<endl;
  rabinKarp(pattern, text, q);
  cout<<endl;

  return 0;
}
