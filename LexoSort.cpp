#include<bits/stdc++.h>
using namespace std;
int main()
{
   int N;
   cin>>N;
   N++;
   vector<string> L(N);
   for(int i=0;i<N;i++)
   {
       getline(cin, L[i]);
   }


        string temp;
       for(int i = 0; i < N-1; ++i)
       for( int j = i+1; j < N; ++j)
       {
          if(L[i] > L[j])
          {
            temp = L[i];
            L[i] = L[j];
            L[j] = temp;
          }
    }

   for(int i=0;i<N;i++)
   {
        cout<<L[i];
        cout<<endl;
    }
}

