#include<bits/stdc++.h>
using namespace std;
bool leap(int y)
{
    if(y%400==0)
        return true;
    else if(y%4==0)
        if(y%100!=0)
            return true;
        else
            return false;
    else
        return false;

}
void date(int y)
{
    if(y<1918)
    {
        if(y%4==0)
            cout<<12<<".0"<<9<<'.'<<y;
        else
            cout<<13<<".0"<<9<<'.'<<y;
    }
    else if(y>1918)
    {
        if(leap(y)==true)
            cout<<12<<".0"<<9<<'.'<<y;
        else
            cout<<13<<".0"<<9<<'.'<<y;
    }
    else
    {
        cout<<26<<".0"<<9<<'.'<<y;
    }
}
int main()
{
    int y;
    cin>>y;
    date(y);
}
