#include<bits/stdc++.h>
using namespace std;
#define N 8
vector<vector<bool> > board(N, vector<bool>(N,false));
int counter = 0;
bool isSafe(int r,int c)
{
	//checking vertical column
	for(int i=0;i<r;i++)
		if(board[i][c]==true)
			return false;
	//checking left upper diagonal
	int R=r-1, C=c-1;
	while(R>=0&&C>=0)
	{
		if(board[R][C]==true)
			return false;
		R--;
		C--;
	}
	//checking right upper diagonal
	R=r-1;
	C=c+1;
	while(R>=0&&C<N)
	{
		if(board[R][C]==true)
			return false;
		R--;
		C++;
	}
	return true;
}


void SolveQueen(int r)
{
	//base case
	if(r==N)
		{
			counter++;
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<N;j++)
					cout<<board[i][j]<<' ';
				cout<<endl;
			}
			cout<<endl;
		}	
	//recursive case
	else
	{
		for(int i=0;i<N;i++)
		{
			if(isSafe(r,i))
			{
				board[r][i]=true;
				SolveQueen(r+1);
				board[r][i]=false;
			}
		}
	}		
}

int main()
{
	SolveQueen(0);
	cout<<endl<<endl<<counter;
}