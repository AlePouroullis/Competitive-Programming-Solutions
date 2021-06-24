#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> movies;
    for(int i = 0; i < n; i++){
        int start, end_;
        cin >> start >> end_;
        movies.push_back({end_, start});
    }
    sort(movies.begin(), movies.end());
    multiset<int> end_times;
    for(int i = 0; i < k; i++){
        end_times.insert(0);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        auto it = end_times.upper_bound(movies[i].second);
        if(it == begin(end_times)) continue;
        end_times.erase(--it);
        end_times.insert(movies[i].first);
        ans++;
    }
    cout << ans << endl;
}
