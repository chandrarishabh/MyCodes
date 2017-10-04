#include<iostream>
using namespace std;
int main()
{
    int t;
     cin>>t;
    if(t<=100&&1<=t)
    {
    for(int c=0;c<t;c++){
        int N=100,m=0;
        cin>>N;
        if(1<=N&&N<=1000000)
        {
            int big[20000   ];
            big[0]=1;
            for(int i=1;i<20000;i++) big[i]=0;

            for(int J=1;J<=N;J++)
            {

                int temp=0;
                for(int k=0;k<20000;k++)
                {
                    int c= big[k]*J + temp;
                    big[k]=c%10;
                    temp=c/10;

                }
            }


        for(int i=20000-1;i>=0;i--) if(big[i]!=0){m=i; break;};
        for(int l=m;l>=0;l--) cout<<big[l];
        }
        cout<<endl;
        }
    }
}

