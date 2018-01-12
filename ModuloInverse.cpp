#include<iostream>
#include<cmath>
using namespace std;

int modularExponentiation(int a, int p, int m)
{
	if(p==0) return 1;
	if(p&1)
	{
		int temp = modularExponentiation(a,(p-1)/2,m)%m;
		return (a*temp*temp)%m;
	}
	else
	{
		int temp;
		temp=modularExponentiation(a,p/2,m)%m;
		return (temp*temp)%m;
	} 
}

//NAIVE APPROACH
/*int modularInverse(int a, int m)
{
	for(int i=1;i<m;i++)
	{
		if((a*i)%m==1)
			return i;
	}
	return -1;
}*/

int x,y,d;
void extendedEuclid(int a, int b)
{
	if(b==0)
	{
		x=1;
		y=0;
		d=a;
	}
	else
	{
		extendedEuclid(b,a%b);
		int temp=y;
		y=x-(a/b)*y;
		x=temp;
	}
}

//USING EXTENDED EUCLID best to use
int modularInverse_EE(int a, int p)
{
	extendedEuclid(a, p);
	return (p+x%p)%p;
}

//USING FERMATs LITTLE THEOREM only when p is prime
int modularInverse_FLT(int a, int p)
{
	return modularExponentiation(a, p-2, p);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		cout<<modularInverse_EE(a,b);
		cout<<endl;
	}	


}