#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	    bool isSafe1(int row, int col, vector<string> board, int n)
	    {
	        int duprow = row;
	        int dupcol = col;
	
	        while (row >= 0 && col >= 0)
	        {
	            if (board[row][col] == 'Q')
	            {
	            	return false;
				}
	            row--;
	            col--;
	        }
	        
	        col = dupcol;
	        row = duprow;
	        
	        while (col >= 0)
	        {
	            if (board[row][col] == 'Q')
	            {
	            	return false;	
				}
	            col--;
	        }
	
	        row = duprow;
	        col = dupcol;
	        while (row < n && col >= 0)
	        {
	            if (board[row][col] == 'Q')
	            {
	            	return false;
				}
	            row++;
	            col--;
	        }
	        return true;
	    }

	public:
	    void solve(int col, vector<string> &board, vector<vector<string> > &ans, int n)
	    {
	        if (col == n)
	        {
	            ans.push_back(board);
	            return;
	        }
	        
	        for (int row = 0; row < n; row++)
	        {
	            if (isSafe1(row, col, board, n))
	            {
	                board[row][col] = 'Q';
	                solve(col + 1, board, ans, n);
	                board[row][col] = '0';
	            }
	        }
	    }

	public:
	    vector<vector<string> > solveNQueens(int n)
	    {
	        vector<vector<string> > ans;
	        vector<string> board(n);
	        string s(n, '0');
	        for (int i = 0; i < n; i++)
	        {
	            board[i] = s;
	        }
	        solve(0, board, ans, n);
	        return ans;
	    }
};

bool isValid(vector<vector<char> > &board, int row, int col, char c)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == c)
        {
        	return false;
        }
	
        if (board[row][i] == c)
        {
        	return false;
		}

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
        {
        	return false;
		}
    }
    return true;
}


int main()
{
	cout<<"\n\t**********N QUEEN PROBLEM USING BACKTRACKING ALGORITHM**********"<<endl;
	int n;
	cout<<"\nEnter the value of nxn chessboard: ";
	cin>>n; 
	cout<<endl;
	Solution obj;
	vector<vector<string> > ans = obj.solveNQueens(n);
	for (int i = 0; i < ans.size(); i++)
	{
	    cout << "Arrangement " << i + 1 << "\n";
	    for (int j = 0; j < ans[0].size(); j++)
	    {
	        cout << ans[i][j];
	        cout << endl;
	    }
	    cout << endl;
	}
	cout<<"\n\tHence, there are "<<ans.size()<<" possible arrangements.";
	return 0;
}

