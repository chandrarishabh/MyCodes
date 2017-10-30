//Missing some cases 



#include <bits/stdc++.h>
#define N 4
int counter = 0;
using namespace std;
int GRID[N][N];

bool Valid(int r, int c)
{
    if( (GRID[r-2][c-1]) &&(r-2>=0)&&(c-1>=0))  return false;
    else if( (GRID[r-1][c-2]) &&(r-1>=0)&&(c-2>=0))  return false;
    else if( (GRID[r+1][c-2]) &&(r+1<N)&&(c-2>=0))  return false;
    else if( (GRID[r+2][c-1]) &&(r+2<N)&&(c-2>=0))  return false;

    else return true;
}

void showGrid()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<GRID[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;

}
void MOVE(int c)
{
    for(int r=0;r<(N/2);r++)
    {
        if(c==N)
        {
            counter++;
            showGrid();
            break;
        }
        else
        {
            if(Valid(r,c)==true)
            {
                GRID[r][c]=1;
                MOVE(c+1);
                GRID[r][c]=0;
            }
            else    continue;
        }
    }
}

int main()
{
    MOVE(0);
    cout<<counter;
}

