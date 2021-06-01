#include <bits/stdc++.h>

using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back

vector<string> strings;
string s, perm = "";
int cnt[26], a = 0;

void find_perms(){
    if(perm.size() == s.size()){
        strings.push_back(perm);
        return;
    }

    for(int i = 0; i < 26; i++){
        if(cnt[i]){
            perm += 'a' + i;
            cnt[i]--;
            find_perms();
            cnt[i]++;
            perm.pop_back();
        }
    }
}

int main(){
    cin >> s;
    for(auto c : s) cnt[c-'a']++;
    find_perms();
    cout << strings.size() << endl;
    for(auto t : strings) cout << t << endl;
}
