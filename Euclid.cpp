#include<bits/stdc++.h>
using namespace std;

//EUCLID
int gcd(int a, int b)
{
    if(b==0)    return a;
    else return gcd(b,a%b);
}

//EXTENDED EUCLID
int d,x,y;
void extendedEuclid(int a, int b)
{
    if(b==0)
    {
        d=a;
        x=1;
        y=0;
    }
    else
    {
        extendedEuclid(b,a%b);
        int oldX = x;
        x=y;
        y=oldX - (a/b)*y;
    }
}

int main()
{
    extendedEuclid(16,10);
    cout<<x<<' '<<y<<' '<<d;
}

