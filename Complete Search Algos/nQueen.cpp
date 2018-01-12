//N-Queen Problem (using backtracking algorithm)
#include<bits/stdc++.h>
using namespace std;
int N=8;
int counter = 0;
vector< vector<int> > board(N, vector<int>(N,0));

bool isSafe(vector< vector<int> > &B, int r, int c)
{
    //checking for vertical lane
    for(int i=0;i<N;i++)
        if(B[i][c])
            return false;
    //for upper left diagonal
    for(int i=0;((r-i)>=0)&&((c-i)>=0);i++)
        if(B[r-i][c-i])
            return false;
    //for upper right diagonal
    for(int i=0;((r-i)>=0)&&((c+i)<N);i++)
        if(B[r-i][c+i])
            return false;
    return true;
}

void display()
{
    for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
                cout<<board[i][j]<<' ';
            cout<<'\n';
        }
}

void solution(int R)
{
    if(R==N)
    {
        counter++;
        display();
        cout<<endl;
    }
    else
    {
        for(int C=0;C<N;C++)
        {
            if(isSafe(board,R,C)==false) continue;
            board[R][C]=1;
            solution(R+1);
            board[R][C]=0;
        }
    }
}

int main()
{
        solution(0);
        cout<<counter;
}

