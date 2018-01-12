//REVERSING A STACK USING RECURSION WITHOUT USING ANOTHER STACK

#include<bits/stdc++.h>
using namespace std;

void insertBottom(stack<int> &S, int d)
{
    if(S.empty())
    {
        S.push(d);
    }
    else
    {
        int t =S.top();
        S.pop();
        insertBottom(S,d);
        S.push(t);
    }
}

void recursion(stack<int> &S)
{
    if(S.size()!=1)
    {
        int temp = S.top();
        S.pop();
        recursion(S);
        insertBottom(S,temp);
    }
}

void takeInput(stack<int> &S)
{
    int i;
    cin>>i;
    while(i!=-1)
    {
        S.push(i);
        cin>>i;
    }
}

void printStack(stack<int> S)
{
    while(S.empty()==false)
    {
        cout<<S.top()<<'\n';
        S.pop();
    }
}
int main()
{
    stack<int> X;
    takeInput(X);
    printStack(X);
    recursion(X);
    printStack(X);
}

