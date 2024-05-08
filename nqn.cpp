#include <iostream>
using namespace std; 
#define n 5

bool isSafe(int board[n][n], int row, int col)
{
    int i, j;

    for(int i=0; i<col; i++)
        if(board[row][i])
            return false;
    
    for(int i=row, j=col; i>=0 && j>=0; i--, j--)
        if(board[i][j])
            return false;

    for(int i=row, j=col; i<n && j>=0; i++, j--)
        if(board[i][j])
            return false;

    return true;
}

bool solve(int board[n][n], int col)
{
    if(col>=n)
        return true;

    for(int i=0; i<n; i++)
    {
        if(isSafe(board, i, col))
        {
            board[i][col] = 1;

            if(solve(board, col+1))
                return true;

            board[i][col] = 0;
        }
    }
    return false;
}

int main (){

    // int n;
    // cout<<"Enter n : ";
    // cin>>n;

    int board[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            board[i][j] = 0;
        }
    }

    bool ans = solve(board, 0);


    if(ans)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j])
                    cout<<"Q"<<" ";
                else    
                    cout<<". ";
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"Solution does not exist";
    }

    return 0;
}
