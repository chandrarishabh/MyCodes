#include<bits/stdc++.h>
#define ll long long
#define bigprime 99999999977LL 
using namespace std;
//Checking if prime in O(root N) 
bool isPrime(ll n)
{
	if(n%2==0)	return false;
	for(ll i=3;i*i<=n;i+=2)
		if(n%i==0)
			return false;
	return true;
}

//Sieve of Eratosthenes runs in O(nloglogn)
vector<bool> sieve(ll N)
{
	vector<bool> my_sieve(N+1,true);
	my_sieve[0]=false;
	my_sieve[1]=false;
	for(ll i=2;i*i<=N;i++)
		if(my_sieve[i])	
			for(ll j=i*i;j<=N;j=j+i)
				my_sieve[j]=false;
	for(ll i=1;i<=N;i++)
		if(my_sieve[i])	cout<<i<<' ';
	return my_sieve;
}

//prime factorisation in O(root N)
vector<ll> factorize(ll n)
{
	vector<ll> factors;
	for(ll i=2; i*i<=n;i++)
		while(n%i==0)
		{
			factors.push_back(i);
			n=n/i;
		}
	if(n!=1) factors.push_back(n);
	for(auto i:factors)
			cout<<i<<' ';	
	return factors;
}

//prime factorisation in O(logN) by using an array
//of numbers which contains smallest prime divisor
//Although preparing this helpArray takes O(NloglogN)
//time, once prepared it can be used to calculate 
//prime factors in O(logN)

vector<ll> make_minPrime(int MAX)
{
	vector<ll> minPrime(MAX+1,0);
	minPrime[1]=1;
	for(ll i=2;i<=MAX;++i)
	{
		if(!minPrime[i])
		{
			minPrime[i]=i;	
			for(ll j=i*i;j<=MAX;j=j+i)
			{
				if(!minPrime[j]) minPrime[j]=i;
			}
		}	

	}
	for(auto i:minPrime)
			cout<<i<<' ';
	return minPrime;
}
//The above function will prepare an array which will
//contain minimum prime divisor of each number.
vector<ll> factorize_fast(ll n,vector<ll> minPrime)
{
	vector<ll> factors;
	while(n!=1)
	{
		factors.push_back(minPrime[n]);
		n/=minPrime[n];
	}
	for(auto i:factors)
			cout<<i<<' ';	
	return factors;
}

int main()
{
	factorize(109546051211LL);
}
