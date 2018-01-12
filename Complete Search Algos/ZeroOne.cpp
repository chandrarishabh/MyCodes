#include<bits/stdc++.h>
using namespace std;

vector<int> X;
int n=100;
void search()
{
	if(X.size()==n)
	{
        for(int i=0;i<n;i++)
            cout<<X[i];
        cout<<endl;
	}
	else
	{
        X.push_back(0);
        search();
        X.pop_back();
        X.push_back(1);
        search();
        X.pop_back();
	}
}

int main()
{
	search();
}

