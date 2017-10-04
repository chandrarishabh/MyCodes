#include <iostream>
#include <math.h>
using namespace std;
int main()
{
   int num[200];
   for(int i =0;i<200;i++) num[i]=0;
   int N,k,i=0;
   N=484;
   while(N!=0)
   {
        k=N%10;
        num[i]=k;
        i++;
        N=N/10;
   }

   for(int i =0;i<20;i++) cout<<num[i];
   int p=2168,temp=0;i=0;
   cout<<endl;
   do
   {
        int c = num[i]*p + temp;
        num[i]=c%10;
        temp=c/10;
        i++;
   }while(temp!=0);
   for(int i =0;i<20;i++) cout<<num[i];
}
