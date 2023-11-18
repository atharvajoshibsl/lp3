#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &board, int r, int c, int n){
    for(int row=0;row<r;row++){
        if(board[row][c]==1){
            return false;
        }
    }

    int row =r;
    int col =c;
    while(row>=0 && col>=0){
        if(board[row][col]==1){
            return false;
        }
        row--;
        col--;
    }

    row =r;
    col =c;
    while(row>=0 && col<n){
        if(board[row][col]==1){
            return false;
        }
        row--;
        col++;
    }

    return true;
}

void printBoard(vector<vector<int>> board, int n){
	for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
			if(board[i][j] == 1) cout << "[Q]";
			else cout << "[]";
		}
        cout << endl;
	}
	cout << endl;
	cout << endl;
}


void nQueen(vector<vector<int>> board, int x, int n){
    if(x == n){
        printBoard(board, n);
		return;
    }

    for(int col=0;col<n;col++){
        if(isSafe(board,x,col,n)){
            board[x][col]=1;
            nQueen(board,x+1,n);
            board[x][col]=0;
        }
    }
}


int main(){
    int n;
    cin >> n;
    
    vector<vector<int>> board(n,vector<int>(n,0));
	
	nQueen(board, 0, n);
	
	cout << "--------All possible solutions--------";
	
    return 0;
}
