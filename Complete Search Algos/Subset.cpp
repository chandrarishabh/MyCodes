#include<bits/stdc++.h>
using namespace std;

vector<int> subset;
void Subset(int k, int n)
{
    if(k==n)
    {
        if(subset.size()!=0)
            {
                for(int i=0;i<subset.size();i++)
                    cout<<subset[i]<<' ';
                cout<<'\n';
            }
        else
            cout<<"Null Set!"<<'\n';
    }
    else
    {
        Subset(k+1,n);
        subset.push_back(k);
        Subset(k+1,n);
        subset.pop_back();
    }
}
int main()
{
    Subset(0,5);
}

