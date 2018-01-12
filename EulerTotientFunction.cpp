#include<bits/stdc++.h>
#define ll long long
#define debug cout<<"debug"<<endl
using namespace std;

vector<ll> factors(int N)
{
	vector<ll> facs;
	for(ll i=2;i*i<=N;++i)
	{
		if(N%i==0)
		{
			facs.push_back(i);
			while(N%i==0)
			{
				N=N/i;
			}
		}
	}
	if(N!=1)	facs.push_back(N);	
	return facs;

}

ll ETF(int n)
{
	if(n==0||n==1)	return 1;
	vector<ll> my_factors = factors(n);
	ll ans=n;
	for(auto i : my_factors)
	{
		ans = (ans/i) * (i-1LL);
	}
	return ans;
}
int main()
{
	int i;
	cin>>i;
	cout<<ETF(i);
}