#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &board,int r,int c,int n)
{
    for(int row=0;row<r;row++)
    {
        if(board[row][c]==1)
        {
            return false;
        }
    }
    int row=r;
    int col=c;

    while(row>=0 && col>=0)
    {
        if(board[row][col]==1)
        {
            return false;
        }
        row--;
        col--;
    }
    row=r;
    col=c;
    while(row>=0 && col<n)
    {
        if(board[row][col]==1)
        {
            return false;
        }
        row--;
        col++;
    }
    return true;
}

void printBoard(vector<vector<int>> board,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j]==1) cout<<"[Q]";
            else    cout<<"[]";
        }
        cout<<endl;
    }
    cout<<endl;
}

void helper(vector<vector<int>> board,int r,int n)
{
    if(r==n)
    {
        printBoard(board,n);
        return;
    }
    for(int c=0;c<n;c++)
    {
        if(isSafe(board,r,c,n))
        {
            board[r][c]=1;
            helper(board,r+1,n);
            board[r][c]=0;
        }
    }
}

int main()
{
    int n;
    cin>>n;

   vector<vector<int>> board(n,vector<int>(n,0));    

    helper(board,0,n);
    
    return 0;
}