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