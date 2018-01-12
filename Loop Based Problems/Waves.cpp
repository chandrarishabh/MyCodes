#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int main()
{
    string text;
    getline(cin,text);
    int N;
    cin>>N;
    int R=0,C=0,p=0;
    vector < vector<char> > A(N, vector<char>(64,' '));
        while(text[C]!='\0')
        {
            loop(i,0,N-1)
            {
                A[i][C]=text[C];
                C++;
            }
            for(int j=N-2;j>0;j--)
            {
                A[j][C]=text[C];
                C++;
            }
        }

        loop(r,0,64)
        {
            loop(c,0,64)
            {
                cout<<A[r][c];
            }
            cout<<endl;
        }
}

