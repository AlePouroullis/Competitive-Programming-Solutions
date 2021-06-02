#include <bits/stdc++.h>

using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back

string s;
int cnt[26] = {0};

int main(){
    cin >> s;
    int n = (int)s.length();
    for(int i = 0; i < n; i++){
        cnt[s[i]-'A']++;
    }
    int cnt_odd = 0;
    string first_half;
    string mid_characters;
    for(int i = 0; i < 26; i++){
        if(cnt[i] % 2 == 1){
            cnt_odd++;
            mid_characters = string(cnt[i], char('A' + i));
        }
        else{
            first_half += string(cnt[i]/2, char('A' + i));
        }
        if((cnt_odd == 1 && n % 2 == 0) || (cnt_odd > 1 && n % 2 == 1)){
            cout << "NO SOLUTION" << endl;
            return 0;
        }
    }
    string second_half = first_half;
    reverse(second_half.begin(), second_half.end());
    cout << first_half << (n % 2 == 1 ? mid_characters : "") << second_half;
}
