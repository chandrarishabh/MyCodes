#include <iostream>
#include <string.h>
using namespace std;

int counter=0;

void MoveHanoi(int disks, char source[], char destination[], char spare[])
{
    counter++;


    if(disks==1)
        cout<<"Move "<<disks<<" from "<<source<<" to "<<destination<<endl<<endl;
    else
    {
        MoveHanoi(disks-1,source,spare,destination);
        cout<<"Move "<<disks<<" from "<<source<<" to "<<destination<<endl<<endl;
        MoveHanoi(disks-1, spare, destination, source);
    }
}

int main()
{
    int n;
    char red[10]="RED";
    char yellow[10]="YELLOW";
    char green[10]="GREEN";
    cout<<"How many disks? \n";
    cin>>n;
    cout<<endl;
    MoveHanoi(n,yellow,green,red);
    cout<<"Total steps "<<counter;

}


