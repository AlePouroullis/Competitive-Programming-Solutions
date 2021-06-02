#include <bits/stdc++.h>
 
using namespace std;
 
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
 
const int dimensions = 8;
 
string board[dimensions];
int ans = 0;
bool col[dimensions] = {false}, diag1[dimensions*2+1] = {false}, diag2[dimensions*2+1] = {false};
 
void solve(int y){
    if(y == dimensions){
        ans++;
        return;
    }
 
    for(int x = 0; x < dimensions; x++){
        if(col[x] || diag1[x+y] || diag2[x-y+dimensions-1] || board[y][x] == '*') continue;
        col[x] = diag1[x+y] = diag2[x-y+dimensions-1] = true;
        solve(y + 1);
        col[x] = diag1[x+y] = diag2[x-y+dimensions-1] = false;
    }
}
 
int main(){
    for(int i = 0; i < dimensions; i++){
        cin >> board[i];
    }
 
    solve(0);
 
    cout 
