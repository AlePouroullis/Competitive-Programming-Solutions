#include <bits/stdc++.h>

using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back

const int MN = 3001;

int n, m, closed[MN] = {false}, order[MN];
vector<int> adj[MN];
bool visited[MN] = {false};
int nodes = 0;

void dfs(int node){
    if(visited[node] || closed[node]) return;
    visited[node] = true;
    nodes++;
    for(int u : adj[node]){
        if(!visited[u]){
            dfs(u);
        }
    }
}

int main(){
    ifstream cin("closing.in");
    ofstream cout("closing.out");
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i < n; i++)
        cin >> order[i];

    dfs(1);
    if(nodes == n)
        cout << "YES" << endl;
    else
        cout <<  "NO" << endl;

    for(int i = 0; i < n-1; i++){
        memset(visited, false, sizeof(visited[0])*(n+1));
        nodes = 0;
        closed[order[i]] = true;
        dfs(order[n-1]);
        if(nodes == n - i - 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
