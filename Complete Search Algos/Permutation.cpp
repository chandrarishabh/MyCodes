#include<bits/stdc++.h>
using namespace std;

const int n=5;

vector<int> permutations;
vector<bool> chosen(n,false);

void search()
{
	if(permutations.size()==n)
	{
		for(int k=0;k<n;k++)
			cout<<permutations[k]<<' ';
		cout<<'\n';
	}
	else
		for(int i=0;i<n;i++)
		{
			if(chosen[i]==true) continue;
			permutations.push_back(i);
			chosen[i]=true;
			search();
			permutations.pop_back();
			chosen[i]=false;
		}
}

int main()
{
	search();
}