#include <bits/stdc++.h>

using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back

string cow_names[] = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
map<string, int> M;

int main(){
    ifstream cin("notlast.in");
    ofstream cout("notlast.out");

    for(string cow_name : cow_names){
        M[cow_name] = 0;
    }
  
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string cow;
        cin >> cow;
        int milk_amount;
        cin >> milk_amount;
        M[cow] += milk_amount;
    }

    vector<pair<int, string>> cows;
    for(map<string, int>::iterator itr = M.begin(); itr != M.end(); itr++){
        cows.push_back({itr->second, itr->first});
    }
    sort(cows.begin(), cows.end());

    int idx = 0;
    while(idx < cows.size() && cows[idx].first == cows[0].first){
        idx++;
    }
    if(idx < cows.size() && (
    idx + 1 == cows.size() || cows[idx].first != cows[idx+1].first)){
        cout << cows[idx].second << endl;
    }else{
        cout << "Tie" << endl;
    }
}
