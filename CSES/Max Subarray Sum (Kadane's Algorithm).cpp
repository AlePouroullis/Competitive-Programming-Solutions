#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    ll curr_max = a[0], global_max = a[0];
    for(int i = 1; i < n; i++){
        curr_max = max(a[i], curr_max + a[i]);
        if(curr_max > global_max)
            global_max = curr_max;
    }
    cout << global_max << endl;
}
