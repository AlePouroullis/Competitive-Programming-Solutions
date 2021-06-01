#include <bits/stdc++.h>

using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back

const int MN = 200;

ll n, x[MN], y[MN], p[MN];
bool is_connected[MN][MN] = {false};
bool visited[MN] = {false};

int dfs(int node){
    int reach = 0;
    visited[node] = true;
    for(int i = 0; i < n; i++){
        if(!visited[i] && is_connected[node][i]){
            reach += dfs(i) + 1;
        }
    }
    return reach;
}

int main(){
    ifstream cin("moocast.in");
    ofstream cout("moocast.out");
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> p[i];

    for(int i = 0; i < n; i++){
        for(int j = 0;  j < n; j++){
            ll distance = (x[i] - x[j])*(x[i] - x[j]) +
                (y[i] - y[j])*(y[i]-y[j]);
            if(p[i]*p[i] >= distance)
                is_connected[i][j] = true;
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        memset(visited, false, sizeof(visited[0])*MN);
        int temp = dfs(i) + 1;
        ans = max(ans, temp);
    }

    cout << ans << endl;
}
