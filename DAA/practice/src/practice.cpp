#include <bits/stdc++.h>
using namespace std;

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n,vector<int> &leftRow, vector<int> &upperDiag, vector<int> &lowerDiag)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (leftRow[row] == 0 && lowerDiag[row + col] == 0 && upperDiag[n - 1 + col - row] == 0)
        {
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiag[row + col] = 1;
            upperDiag[n - 1 + col - row] = 1;
            solve(col + 1, board, ans, n, leftRow, upperDiag, lowerDiag);
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiag[row + col] = 0;
            upperDiag[n - 1 + col - row] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '_');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    vector<int> leftRow(n, 0);
    vector<int> upperDiag(2 * n - 1, 0);
    vector<int> lowerDiag(2 * n - 1, 0);
    solve(0, board, ans, n, leftRow, upperDiag, lowerDiag);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<string>> ans= solveNQueens(n);

    for(auto it: ans)
    {
        for(auto jt: it)
        {
            cout<<jt<<endl;
        }
        cout<<endl;
    }

    cout << "--------All possible solutions--------";

    return 0;
}

/*
Time Complexity: O(N!)
Auxiliary Space: O(N^2)
*/
