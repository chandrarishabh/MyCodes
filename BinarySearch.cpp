#include <iostream>
#include <math.h>
using namespace std;

int binarysearch(int arr[], int N, int S)
{
    int counter = 0;
    int beg=0, last=N-1; int mid;
    while(beg<=last)
    {
        counter++;
        cout<<"\nIteration : "<<counter;
        mid = (beg+last)/2;
        if(arr[mid]==S)
        {
            cout<<"\nElement found at "<<mid+1<<" location!";
            break;
        }
        else if(S<arr[mid])
        {
            last=mid-1;
        }
        else if(arr[mid]<S)
        {
            beg=mid+1;
        }

    }
    cout<<"\nElement not found!";
}

int main()
{
    int arr[8] = {1,4,8,16,32,64,128,256};
    binarysearch(arr,8,256  );

}

