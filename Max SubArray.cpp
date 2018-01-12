#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef vector<int> ARRAY;
int main()
{
    ARRAY in,save;
    int n;
    cin>>n;
    rep(i,0,n)
    {
        int x;
        cin>>x;
        in.push_back(x);
    }
    rep(k,0,n)
    {
        int sum=0;
        rep(j,k,n)
        {
            sum=sum+in.at(j);
            save.push_back(sum);
        }
    }
    sort(save.begin(),save.end(), greater<int>());
    cout<<save.at(0);
}


//kadanes algo
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef vector<int> ARRAY;
int main()
{
    ARRAY in;
    int n;
    cin>>n;
    rep(i,0,n)
    {
        int x;
        cin>>x;
        in.push_back(x);
    }
    int max_ = in.at(0), globalmax_=0;
    rep(i,1,n)
    {
        int temp_sum = max_ + in.at(i);
        max_ = max(temp_sum,in.at(i));
        if(max_>=globalmax_)
            globalmax_=max_;
    }
    cout<<globalmax_;
}


