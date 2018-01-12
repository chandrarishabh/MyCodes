#include <iostream>
#include <string.h>
using namespace std;

int pchecker(char arr[],int s, int e)
{
    if(s==e)
        return 1;
    if(arr[s]==arr[e])
    {
        s++;
        e--;
        if(pchecker(arr,s,e)==1)
            cout<<"Palindrome!";
    }
    else
        {
            cout<<"Not a palindrome!";
            return 0;
        }
}

int main()
{
    char word[100] = "GOD";
    int len = strlen(word);
    pchecker(word,0,len-1);

}

