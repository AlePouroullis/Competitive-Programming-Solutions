// Solution by Alexandros Pouroullis
#include <bits/stdc++.h>

using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back

int n;
string X[7], Y[7];
string cows[8] = {"Beatrice", "Bella", "Belinda", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
vector<vector<string>> solutions;
vector<string> temp;
bool selected[8] = {false};

bool beside(string cow1, string cow2){
    int cow1_idx, cow2_idx;
    for(int i = 0; i < 8; i++){
        if(temp[i] == cow1)
            cow1_idx = i;
        else if(temp[i] == cow2)
            cow2_idx = i;
    }
    return (cow1_idx == cow2_idx-1) || (cow1_idx == cow2_idx+1);
}

void solve(){
    if(temp.size() == 8){
        bool valid = true;
        for(int i = 0; i < n; i++){
            if(!beside(X[i], Y[i])){
                valid = false;
                break;
            }
        }
        if(valid)
            solutions.push_back(temp);
        return;
    }

    for(int i = 0; i < 8; i++){
        if(selected[i]) continue;
        selected[i] = true;
        temp.push_back(cows[i]);
        solve();
        selected[i] = false;
        temp.pop_back();
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        string discard;
        cin >> X[i] >> discard >> discard >> discard >> discard >> Y[i];
    }

    solve();
    sort(solutions.begin(), solutions.end());
    for(int i = 0; i < 8; i++){
        cout << solutions[0][i] << endl;
    }
}
