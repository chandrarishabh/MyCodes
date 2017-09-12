//GCD USING EUCLID's ALGORITHM.
#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if(b==0)
        return a;
    else
        gcd(b, a%b);
}

int main()
{
    cout<<gcd(2322,654);
}
