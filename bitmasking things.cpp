#include<bits/stdc++.h>
#define debug(x) cout<<#x<<" = "<<x;
using namespace std;
int ar[] = {6,2,4,8};
int ar_size = sizeof(ar)/sizeof(int);
vector<int> s;
void printSubsets(int i)
{
    if(i==sizeof(ar)/sizeof(int))
    {
        cout<<'{';
        for(auto x:s)
            cout<<x<<',';
        cout<<'}'<<endl;
        return;
    }
    s.push_back(ar[i]);
    printSubsets(i+1);
    s.pop_back();
    printSubsets(i+1);
}

void printsubsetsBM(int *ar, int s)
{
    for(int mask=0;mask<(1<<s);mask++)
    {
        for(int j=0;j<s;++j)
        {
            if(mask&(1<<j))
                cout<<ar[j]<<' ';
        }
        cout<<endl;
    }

}
int ar_sum()
{
    int sum=0;
    for(int i=0;i<ar_size;++i)
    {
        sum+=ar[i];
    }
    return sum;
}

void halfSum(int n)
{
    for(int mask=0;mask<pow(2,ar_size);++mask)
    {
        vector<int> o,z;
        int sum=0;
        for(int i=0;i<ar_size;++i)
        {
            if(mask&(1<<i))
            {
                sum+=ar[i];
                o.push_back(ar[i]);
            }
            else z.push_back(ar[i]);
        }
        if(sum==n)
        {
            cout<<endl;
            cout<<"Array ONE : ";
            for(int k:o)
                cout<<k<<' ';
            cout<<endl<<"Array TWO : ";
            for(int k:z)
                cout<<k<<' ';
            cout<<"\n--------------------\n";
        }

    }
}

int main()
{
    halfSum((ar_sum()/2));
}

