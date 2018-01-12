#include<bits/stdc++.h>
using namespace std;
//Takes time complexity O(n)
int fac(int n)
{
    if(n==0)    return 1;
    else return fac(n-1)*n;
}
int C(int n, int r)
{
    int x = fac(n)/(fac(n-r)*fac(r));
    return x;
}
//Using recursive relation
int C_(int n, int k)
{
    //base case
    if(n==k||k==0)
        return 1;
    else
        return C_(n-1,k)+C_(n-1,k-1);
}
//Implemented DP
int C__(int n,int k)
{
    int A[n+1][k+1];
    for(int i=0;i<=n;i++)
    for(int j=0;j<=i&&j<=k;j++)
    {
        if(j==0||j==i)
            A[i][j]=1;
        else
        {
            A[i][j]=A[i-1][j-1]+A[i-1][j];
        }
    }
    return A[n][k];
}
int main()
{
    cout<<C__(6,4);
}

