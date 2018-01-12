#include<bits/stdc++.h>
using namespace std;
//This has complexity O(b) for pow(a,b)=a^b
int power(int a, int b)
{
    int ans=1;
    for(int i=1;i<=b;i++)
        ans*=a;
    return ans;
}
//This has complexity O(log b) thus much better. 
long int quick_power(int a, int b)
{
    int ans=1;
    if(b==0)    return 1;
    else{
        int temp=quick_power(a,b/2);
        if(b%2!=0)
            return temp*temp*a;
        else
            return temp*temp;
    }
}
   //Iterative O(log b) code
int quick__power(int a, int b)
{
    int ans=1;
    while(b!=0)
    {
        if(b%2!=0)
            ans=ans*a;
        a=a*a;
        b=b/2;
    }
    return ans;
}
 
int main()
{
    cout<<power(2,30);
}

