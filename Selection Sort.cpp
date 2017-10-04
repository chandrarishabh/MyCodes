#include <iostream>
#include <math.h>
using namespace std;

int selection_sort(int arr[], int N)
{
    int loc, temp;
    for(int i=0;i<N-1;i++)
    {
        loc=i;
        for(int j=i+1;j<N;j++)
        {
            if(arr[j]<=arr[loc])
            {
                loc=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[loc];
        arr[loc]=temp;

    }
    for(int i=0;i<N;i++) cout<<" "<<arr[i];
}

int main()
{
    int arr[] = {22, 11, 99, 9,88, 45, 7};
    selection_sort(arr,7);

}
