//CIRCULAR QUEUE!
#include<iostream>
#include<string.h>
using namespace std;

const int MAX=5;
int a[MAX];
int FRONT=0, REAR=0;
int counter=0;
void enQ(int x)
{
    if(counter==MAX) cout<<"OVERFLOW!!";
    else
        counter++;
        a[REAR]=x;
        REAR = (REAR+1)%MAX;
}
void dQ()
{
   if(counter==0) cout<<"UNDERFLOW!!";
   else if(FRONT==MAX-1) {a[FRONT]=0;FRONT=0;counter--;}
   else {a[FRONT]=0;FRONT++;counter--;}

}
void showQ()
{
    cout<<endl<<endl;
    for(int i=0;i<MAX;i++)
        cout<<a[i]<<" ";
}

