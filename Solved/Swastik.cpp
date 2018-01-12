#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    char grid[t][t];
    for(int r=0;r<t;r++)
    {
    for(int c=0;c<t;c++)
    {
            grid[r][c]=' ';
    }
    }
    for(int r=0;r<(t/2);r++)
    {
        grid[r][0]='*';
        grid[r][t/2]='*';
    }
    for(int r=t/2;r<t;r++)
    {
        grid[r][t/2]='*';
        grid[r][t-1]='*';
    }
    for(int r=0;r<(t/2);r++)
    {
        grid[t/2][r]='*';
        grid[t-1][r]='*';
    }
    for(int r=t/2;r<t;r++)
    {
        grid[0][r]='*';
        grid[t/2][r]='*';
    }

    for(int r=0;r<t;r++)
    {
    for(int c=0;c<t;c++)
    {
            cout<<grid[r][c];
        }
        cout<<endl;
    }
}

