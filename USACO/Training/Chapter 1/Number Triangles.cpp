// Solution by Alexandros Pouroullis
/*
ID : ---
LANG: C++
TASK : numtri
*/

#include <bits/stdc++.h>

using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back

int main(){
    ifstream cin("numtri.in");
    ofstream cout("numtri.out");

    int R;
    cin >> R;

    int grid[R][R];
    int dp[R][R] = {0};
    for(int i = 0; i < R; i++){
        for(int j = 0; j <= i; j++){
            cin >> grid[i][j];
            if(i == R-1)
                dp[i][j] = grid[i][j];
        }
    }

    for(int i = R-2; i >= 0; i--){
        for(int j = i; j >= 0; j--){
            dp[i][j] += grid[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
        }
    }

    cout << dp[0][0] << endl;
}
