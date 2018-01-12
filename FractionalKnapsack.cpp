//APPLIED GREEDY APPROACH TO THIS PROBLEM RESULTING IN WRONG ANSWER :(
//NEEDS TO BE DONE USING DP APPROACH
//WA ON SPOJ CURRENTLY

#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<"="<<x<<endl; 
using namespace std;
bool comp(pair<pair<ll,ll>,ll> left, pair<pair<ll,ll>,ll> right)
{
	return left.second>right.second;
}
void driver()
{
	ll c, n;
	cin>>c>>n;
	vector<pair<pair<ll,ll>,ll> > items;
	while(n--)
	{
		ll s, v;
		cin>>s>>v;
		items.push_back(make_pair(make_pair(s,v),v/s));
	}
	sort(items.begin(),items.end(),comp);
	double csize = 0, i=0, value=0;
	while(i<items.size()&&csize<c)
	{
		ll ts = items[i].first.first;
		if(ts<=c-csize)
		{
			value += ts*items[i].second;
			csize +=ts;
		}
		else
		{
			ll remain = c - csize;
			value += (items[i].first.second)*(((double)remain)/ts);
			csize += (items[i].first.first)*(((double)remain)/ts);
		}

		i++;
	}
	cout<<value<<endl;
}
int main()
{
	driver();
}