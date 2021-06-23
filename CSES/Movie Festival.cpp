#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> movies;
    for(int i = 0; i < n; i++){
        int start, end_;
        cin >> start >> end_;
        movies.push_back({start, end_});
    }
    sort(movies.begin(), movies.end(), cmp);
    int ans = 0;
    int currentEventEnd = -1;
    for(int i = 0; i < n; i++){
        if(movies[i].first >= currentEventEnd){
            ans++;
            currentEventEnd = movies[i].second;
        }
    }
    cout << ans << endl;
}
