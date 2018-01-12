#include<bits/stdc++.h>
using namespace std;
vector<int> maze;
void greedy(int x, int *y)
{
    for(int i=7;i>=0;i--)
    {

        int z=x/(*(y+i));
        for(int j=0;j<z;j++)
        {
            maze.push_back(*(y+i));
        }
        x=x%(*(y+i));
    if(x==0) break;
    }
}

int main()
{

    int y[] ={1,2,5,10,20,50,100,200};
    greedy(520,y);
    for(int i=0;i<maze.size();i++)
        cout<<maze.at(i)<<'\t';
}

//Not best solution because this works only in euro coins set. Dynamic Programming approach gives best results.
