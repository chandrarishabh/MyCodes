#include<bits/stdc++.h>
using namespace std;
int binarySearchLoop(int* ar, int s, int n)
{
    int low=0,high=s-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(ar[mid]<n)   low=mid+1;
        else if(ar[mid]>n)  high=mid-1;
        else return mid;
    }
    return -1;
}

bool bs(int* ar, int low, int high, int n)
{
    if(low>high)  return false;
    int mid = low + (high-low)/2;
    if(ar[mid]==n)
        return true;
    else
    {
        if(ar[mid]>n)
            return bs(ar, low, mid-1,n);
        else
            return bs(ar, mid+1,high,n);
    }
}

int main()
{
    int ar[]={0,1,2,3,4,5,6,7,8,9};
    cout<<bs(ar,0,9,56);
}
