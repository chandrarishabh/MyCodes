#include<bits/stdc++.h>
#define loop(a,b,k) for(int k=a;k<=b;k++)
 using namespace std;
 int main()
 {
    int n;
    cin>>n;
    int S=((2*n)-1);
    vector<vector<int> > A(S,vector<int> (S));
    int P = n;

    for(int i=0,l=S-1;;i++,l--)
    {
        loop(i,l,k) A[i][k]=P;
        loop(i,l,k) A[l][k]=P;
        loop(i,l,k) A[k][i]=P;
        loop(i,l,k) A[k][l]=P;
        P--;
        if(i==l) break;
    }
    loop(0,S-1,i)
    {
        loop(0,S-1,j)
        {
            cout<<A[i][j]<<' ';
        }
        cout<<'\n';
    }
 }

