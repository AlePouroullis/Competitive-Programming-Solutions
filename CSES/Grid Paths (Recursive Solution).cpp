#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;
using vc = vector<char>;
using vs = vector<string>;
using str = string;

#define FastIO ios_base::sync_with_stdio(0); cin.tie(0)
#define pb push_back
#define mp make_pair
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define ins insert
#define f first
#define sz(x) (ll)(x).size()
#define len(x) (ll)(x).length()
#define FOR(i, a, b) for(ll i=a; i<b; ++i)
#define ROF(i, b, a) for(ll i=(b)-1; i>=a; --i)
#define EACH(a, x) for(auto& a: x)
#define lb(a, x) lower_bound(all(a), x) - begin(a)
#define ub(a, x) upper_bound(all(a), x) - begin(a)

void setIO(string fileName = ""){
	FastIO;
	if(len(fileName)){
		freopen((fileName+".in").c_str(), "r", stdin);
		freopen((fileName+".out").c_str(), "w", stdout);
	}
}

const int n = 7;
bool visited[n][n];
int ans = 0, steps = 0;
string directions;
map<char, int> compass;
int reserved[n*n-1];
const int U = 0, D = 1, L = 2, R = 3, Q_mark = -1;

void findPaths(int r, int c){
    if(r == n-1 && c == 0){
        if(steps == n*n-1) ans++;
        return;
    }

    if(
       // Out of bounds
       (c < 0 || c >= n || r < 0 || r >= n)
       ||
       // Already visited
       (visited[r][c])
       ||
       // Hits top/bottom wall or runs into itself, splitting the board into two halves of univisited blocks
       ((r == 0 || r == n-1 || (visited[r+1][c] && visited[r-1][c])) && c > 0 && c < n-1 &&
        !visited[r][c-1] && !visited[r][c+1])
       ||
       // Hits left/right wall or runs into itself, splitting the board into two halves of univisited blocks
       ((c == 0 || c == n-1 || (visited[r][c-1] && visited[r][c+1])) && r > 0 && r < n-1 &&
        !visited[r-1][c] && !visited[r+1][c])
    )
    return;

    visited[r][c] = true;

    if(reserved[steps] == Q_mark){
        if(r > 0 && !visited[r-1][c]){
            steps++;
            findPaths(r-1, c);
            steps--;
        }
        if(r + 1 < n && !visited[r+1][c]){
            steps++;
            findPaths(r+1, c);
            steps--;
        }
        if(c > 0 && !visited[r][c-1]){
            steps++;
            findPaths(r, c-1);
            steps--;
        }
        if(c + 1 < n && !visited[r][c+1]){
            steps++;
            findPaths(r, c+1);
            steps--;
        }
    }else{
        switch(reserved[steps]){
            case U:
                steps++;
                findPaths(r-1, c);
                steps--;
                break;
            case D:
                steps++;
                findPaths(r+1, c);
                steps--;
                break;
            case L:
                steps++;
                findPaths(r, c-1);
                steps--;
                break;
            case R:
                steps++;
                findPaths(r, c+1);
                steps--;
        }
    }

    visited[r][c] = false;
}

int main(){
    compass['U'] = U;
    compass['D'] = D;
    compass['L'] = L;
    compass['R'] = R;

    cin >> directions;

    for(int i = 0; i < directions.length(); i++){
        if(directions[i] == '?')
            reserved[i] = Q_mark;
        else
            reserved[i] = compass[directions[i]];
    }

    findPaths(0, 0);
    cout << ans << endl;
}
