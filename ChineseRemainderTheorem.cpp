#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for(long long i=a;i<=b;++i)
#define debug cout<<"debug"<<endl;
using namespace std;

ll x,y,gcd;
void ExtendedEuclid(ll a, ll m)
{
	if(m==0)
	{
		x=1;
		y=0;
		gcd=a;
	}
	else
	{
		ExtendedEuclid(m,a%m);
		ll oldX = x;
		x=y;
		y=oldX-(a/m)*y; 
	}
}
ll ModularInverse(ll a, ll p)
{
	ExtendedEuclid(a,p);
	return (x%p + p)%p;
}

ll CRT(vector<ll> num, vector<ll> rem)
{
	ll prod = 1;
	for(ll i=0;i<num.size();++i)
		prod*=num[i];
	vector<ll> pp;
	F(j,0,num.size()-1)
		pp.push_back(prod/num[j]);
	vector<ll> inv;
	F(k,0,num.size()-1)
	{
		inv.push_back(ModularInverse(pp[k],num[k]));
	}
	ll x=0;
	ll temp;
	F(c,0,num.size()-1)
	{
		
		temp=(rem[c]*pp[c])%prod;
		temp=(temp*inv[c])%prod;
		x=(x+temp)%prod;
	}
	return x%prod;
}

int main()
{
	vector<ll> num;
	vector<ll> rem;
	ll s;
	cin>>s;
	F(i,1,s)
	{
		ll x,y;
		cout<<"Enter num["<<i-1<<"] : ";
		cin>>x;
		cout<<"Enter rem["<<i-1<<"] : ";
		cin>>y;
		num.push_back(x);
		rem.push_back(y);
	}
	cout<<CRT(num,rem);
	cout<<endl;
}