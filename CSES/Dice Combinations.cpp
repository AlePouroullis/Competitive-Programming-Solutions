#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    char grid[n][n];
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
        cin >> grid[i][j];

    ll dp[n][n];
    memset(dp, 0, sizeof(dp));
    if(grid[0][0] != '*')
        dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] != '*'){
                if(i > 0)
                    dp[i][j] += dp[i-1][j];
                if(j > 0)
                    dp[i][j] = (dp[i][j] + dp[i][j-1])%(1000000007);
            }
        }
    }
    cout << dp[n-1][n-1] << endl;
}
