/*
ID: ---
LANG: C++
TASK: barn1
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
    ifstream cin("barn1.in");
    ofstream cout("barn1.out");
    int m, s, c;
    cin >> m >> s >> c;
    int stalls[c];
    for(int i = 0; i < c; i++){
        cin >> stalls[i];
    }

    bool occupied[s+1] = {false};
    for(int stall : stalls){
        occupied[stall] = true;
    }

    int ans = 0;
    list<int> gaps;
    int boards = 0;
    for(int i = 1; i <= s; i++){
        if(occupied[i])
            ans++;
        if(occupied[i-1] == true && occupied[i] == false && i < s){
            int j = i;
            int gap_size = 0;
            while(occupied[j] == false && j <= s){
                gap_size++;
                j++;
            }
            boards++;
            gaps.push_back(gap_size);
        }else if(i == s && occupied[i] == true && occupied[i-1] == false){
            boards++;
        }
    }
    // Because it's possible for all the stalls to be occupied, it's necessary
    // to check for this case. Only one board is used in the case that they're all
    // occupied, so the boards variable is incremented from 0 to 1.
    if(boards == 0)
        boards++;

    gaps.sort();

    while(boards > m){
        ans += gaps.front();
        gaps.pop_front();
        boards--;
    }

    cout << ans << endl;
}
