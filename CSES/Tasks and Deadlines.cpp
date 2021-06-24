#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> tasks;
    for(int i = 0; i < n; i++){
        int a, d;
        cin >> a >> d;
        tasks.push_back({a, d});
    }
    sort(tasks.begin(), tasks.end());
    ll ans = 0;
    ll current_time = 0;
    for(int i = 0; i < n; i++){
        current_time += tasks[i].first;
        ans += tasks[i].second - current_time;
    }
    cout << ans << endl;
}
