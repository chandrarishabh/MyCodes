#include <iostream>
using namespace std;
char grid[100][100];
int dR[]={-1,0,1,0};
int dC[]={0,-1,0,1};
int r=0,c=0;
void takeInput()
{
	for(int i=0;i<r;++i)
		for(int k=0;k<c;++k)
			cin>>grid[i][k];
}
void printGrid()
{
	cout<<endl;
	for(int i=0;i<r;++i)
	{
		for(int k=0;k<c;++k)
		{
			cout<<grid[i][k]<<' ';
		}
		cout<<endl;
	}
}
void FloodFill(int R, int C, char replace, char myChar)
{
	//BASE CASE - when array frame is reached.
	if(C>=c||R<0||R>=r||C<0)
		return;
	//BASE CASE - when boundary character is reached.
	if(grid[R][C]!=replace)
		return;
	//RECURSIVE CASE
	grid[R][C]=myChar;
	for(int k=0;k<4;++k)
	{
		FloodFill(R+dR[k],C+dC[k],replace,myChar);
	}
}
int main()
{
	cin>>c>>r;
	takeInput();
	printGrid();
	FloodFill(6,4,'.','O');
	printGrid();	
}
