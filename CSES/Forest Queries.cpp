#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    bool forest[n+1][n+1];
    memset(forest, 0, sizeof(forest));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char c;
            cin >> c;
            if(c == '*')
                forest[i][j] = 1;
        }
    }

    ll prefix[n+1][n+1];
    memset(prefix, 0, sizeof(prefix));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1]
            - prefix[i-1][j-1] + forest[i][j];
        }
    }

    while(q--){
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << prefix[y2][x2] - prefix[y1-1][x2] - prefix[y2][x1-1] + prefix[y1-1][x1-1] << endl;
    }
}
