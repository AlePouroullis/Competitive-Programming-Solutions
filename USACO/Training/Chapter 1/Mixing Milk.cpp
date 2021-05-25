// Solution by Alexandros Pouroullis
/*
ID: ---
LANG: C++
TASK: milk
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
    fast
    ifstream cin("milk.in");
    ofstream cout("milk.out");
    int n, m;
    cin >> n >> m;

    // farmers[i].first is the price per unit while farmers[i].second is the amount
    // of units available from that farmer.
    vector<pair<int, int>> farmers(m);
    for(int i = 0; i < m; i++)
        cin >> farmers[i].first >> farmers[i].second;

    // Sorts in ascending order of prices.
    sort(farmers.begin(), farmers.end());

    int ans = 0;
    for(int i = 0; i < m; i++){
        if(farmers[i].second <= n){
            n -= farmers[i].second;
            ans += farmers[i].second * farmers[i].first;
        }else{
            ans += farmers[i].first * (n - 0);
            n = 0;
        }
        if(n == 0)
            break;
    }

    cout << ans << endl;
}
