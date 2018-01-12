#include<bits/stdc++.h>
using namespace std;
#define N 9

int grid[9][9]={{0,2,0,  0,0,0,  0,0,0},
			    {0,0,0,  6,0,0,  0,0,3},	
			    {0,7,4,  0,8,0,  0,0,0},	
			 
			    {0,0,0,  0,0,3,  0,0,2},	
			    {0,8,0,  0,4,0,  0,1,0},	
			    {6,0,0,  5,0,0,  0,0,0},	
			 
			    {0,0,0,  0,1,0,  7,8,0},	
			    {5,0,0,  0,0,9,  0,0,0},	
			    {0,0,0,  0,0,0,  0,4,0}};

bool findEmptyBox(int &row, int &col)
{
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{	
			if(grid[i][j]==0)
			{	
				row=i;
				col=j;
				return true;
			}
		}
	return false;	
}

bool isRowSafe(int r, int i)
{
	for(int j=0;j<N;j++)
		if(grid[r][j]==i)
			return false;
	return true;
}

bool isColSafe(int c,int i)
{
	for(int j=0;j<N;j++)
		if(grid[j][c]==i)
			return false;
	return true;
}

bool isSubGridSafe(int r,int c, int K)
{
	int R = r - r%3;
	int C = c - c%3;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(grid[R+i][C+j]==K)	return false;
	return true;
}
void printGrid()
{
	cout<<endl;
	for(int i=0;i<N;i++)
	{
		if(i%3==0)	cout<<endl;
		for(int j=0;j<N;j++)
		{
			if(j%3==0)	cout<<"  ";
			cout<<grid[i][j]<<' ';
		}
		cout<<endl;
	}	
}

bool SolveSudoku()
{
	countsteps++;
	int row=0, col=0;
	//base case
	if(!findEmptyBox(row,col))
	{
		printGrid();
		return true;
	}
	
	for(int i=1;i<=N;i++)
	{
		if(isRowSafe(row,i)&&isColSafe(col,i)&&isSubGridSafe(row,col,i))
		{
			grid[row][col] = i;
			if(SolveSudoku()) return true;
			grid[row][col] = 0;
		}
	}

	return false;

}

int main()
{
	SolveSudoku();
}