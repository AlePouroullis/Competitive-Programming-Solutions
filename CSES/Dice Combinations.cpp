#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    ll dp[n + 1] = {0};
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= min(6, i); j++){
            dp[i] = (dp[i] + dp[i-j])%(1000000007);
        }
    }
    cout << dp[n];
}
