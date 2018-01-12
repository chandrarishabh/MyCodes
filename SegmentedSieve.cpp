#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for(long long i=a;i<=b;++i)
#define debug cout<<"debug"<<endl;
using namespace std;

vector<ll> Sieve(ll n)
{
	vector<ll> primes;
	vector<bool> mark(n+1+10,true);
	mark[0]=mark[1]=false;
	for(ll i=2;i*i<=n;i+=1)
	{
		if(mark[i])
			for(ll j=i*i; j<=n ; j=j+i)
				mark[j]=false;
	}
	for(ll i=0;i<=n;++i)
		if(mark[i])
			primes.push_back(i);

	return primes;	
}

void Segmented_Sieve(ll n, ll m)
{
	ll x = pow(m,0.5);
	vector<ll> p = Sieve(x);
	vector<bool> ss(m-n+1 + 10,true);
	for(int i=0;i<p.size();++i)
	{
		
		ll prime = p[i];
		ll j;
		if(n%prime==0)
			j=n;
		else
			j=((n/prime)+1)*prime;

		if(j==prime) j=j+prime;	
		for(ll k =j;k<=m;k=k+prime)
		{
			ss[k - n] = false;	
		}
	}
	for(ll c=0;c<=m-n;c++)
	{
		if(ss[c])
			printf("%lli\n",c+n);
	}

}

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		if(n==1||n==2)
		{
			vector<ll> p = Sieve(m);
			for(ll c=0;c<p.size();c++)
			{	
				printf("%lli\n", p[c]);
			}
			continue;			
		}
		Segmented_Sieve(n, m);
	}
}	