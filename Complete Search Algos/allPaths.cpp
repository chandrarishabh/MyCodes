//all possible paths in NXN maze from top left to bottom right.ss

#include<bits/stdc++.h>
#define N 3
using namespace std;

vector< vector<int> > maze(N, vector<int>(N,1));
int counter = 0;

void solve(int r, int c)
{
    if(r==N-1&&c==N-1)
        counter++;
    else
    {
        //left
        if((c-1>=0)&&maze[r][c-1])
        {
            maze[r][c-1]=0;
            solve(r,c-1);
            maze[r][c-1]=1;
        }
        //right
        if((c+1<N)&&maze[r][c+1])
        {
            maze[r][c+1]=0;
            solve(r,c+1);
            maze[r][c+1]=1;
        }
        //up
        if((r-1>=0)&&maze[r-1][c])
        {
            maze[r-1][c]=0;
            solve(r-1,c);
            maze[r-1][c]=1;
        }
        //down
        if((r+1<N)&&maze[r+1][c])
        {
            maze[r+1][c]=0;
            solve(r+1,c);
            maze[r+1][c]=1;

        }

    }
}


int main()
{
    maze[0][0]=0;
    solve(0,0);
    cout<<counter;
}


//OPTIMIZATION 1 to go from top left corner to bottom right corner such that
//all tiles traversed exactly once.
#include<bits/stdc++.h>
#define N 7
using namespace std;

vector< vector<int> > maze(N, vector<int>(N,1));
int counter = 0;
bool allcheck()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(maze[i][j]==1)
                return false;
    return true;
}
void solve(int r, int c)
{
    if(r==N-1&&c==N-1&&allcheck()==true)
        counter++;
    else
    {
        //left
       if((c-1>=0)&&maze[r][c-1])
        {
            maze[r][c-1]=0;
            solve(r,c-1);
            maze[r][c-1]=1;
        }
        //right
        if((c+1<N)&&maze[r][c+1])
        {
            maze[r][c+1]=0;
            solve(r,c+1);
            maze[r][c+1]=1;
        }
        //up
       if((r-1>=0)&&maze[r-1][c])
        {
            maze[r-1][c]=0;
            solve(r-1,c);
            maze[r-1][c]=1;
        }
        //down
        if((r+1<N)&&maze[r+1][c])
        {
            maze[r+1][c]=0;
            solve(r+1,c);
            maze[r+1][c]=1;

        }

    }
}


int main()
{
    maze[0][0]=0;
    maze[0][1]=0;
    solve(0,1);
    cout<<counter*2;
}
