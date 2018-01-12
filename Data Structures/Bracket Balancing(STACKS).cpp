#include<bits/stdc++.h>
using namespace std;
bool check()
{
    stack<char> S;
    string input;
    getline(cin, input);
    for(int i=0;i<input.length();i++)
    {
        char c = input[i];
        switch(c)
        {

            case '{':   S.push(c);
                        break;
            case '[':   S.push(c);
                        break;
            case '(':   S.push(c);
                        break;

            case '}':   if(S.empty()==false&&S.top()=='{') S.pop();
                        else return false;
                        break;
            case ']':   if(S.empty()==false&&S.top()=='[') S.pop();
                        else return false;
                        break;
            case ')':   if(S.empty()==false&&S.top()=='(') S.pop();
                        else return false;
                        break;
        }
    }
    if(S.empty()) return true;
}

int main()
{

    if(check())   cout<<"\nBALANCED!";
    else    cout<<"\nNOT BALANCED!";
}
