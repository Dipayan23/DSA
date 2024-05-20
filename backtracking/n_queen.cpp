#include <iostream>
using namespace std;
#define n 8

void display(int board[n][n]){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<board[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    
}

bool isSafe(int board[n][n], int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)
    {
        if (board[row][i]==1)
        {
            return false;
        }
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j]==1)
        {
            return false;
        }
    }
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
    {
        if (board[i][j]==1)
        {
            return false;
        }
    }
    return true;
}

void solveNQueen(int board[n][n],int col){
    if (col>=n)
    {
        display(board);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(board,i,col))
        {
            board[i][col]=1;
            solveNQueen(board,col+1);
        }
        board[i][col]=0;
    }
    
}

int main()
{
    int board[n][n]={0};
    solveNQueen(board,0);
    return 0;
}