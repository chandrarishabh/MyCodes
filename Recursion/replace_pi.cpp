#include<bits/stdc++.h>
using namespace std;
string REPLACE(string x)
{
    if(x.length()<2)
        return x;
    else if(x.substr(0,4) == "3.14")
       return "pi" + REPLACE(x.substr(4));
    else
        return x[0]+REPLACE(x.substr(1));
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<=t;i++)
    {
        string x;
        getline(cin,x);
        cout<<REPLACE(x)<<'\n';

    }


}

