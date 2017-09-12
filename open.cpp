#include <bits/stdc++.h>

using namespace std;

int birthdayCakeCandles(int n, vector <int> ar) {
    // Complete this function
    int temp=ar[n-1], counter = 0;
    for(int i=n-1;i>=0;i--)
    {
        if(ar[i]==temp)
        {
            counter++;
        }
        else
        {
            if(counter==1)
                return temp;
            else
            {
                temp=ar[i];
                counter=1;
            }
        }
    }
    return temp;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    sort(ar.begin(),ar.end());
    int result = birthdayCakeCandles(n, ar);
    cout << result << endl;
    return 0;
}
