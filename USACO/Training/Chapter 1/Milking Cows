// Solution by Alexandros Pouroullis
/*
ID: ---
LANG: C++
TASK: milk2
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
    ifstream cin("milk2.in");
    ofstream cout("milk2.out");
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    if(n == 1){
        cout << a[0].second - a[0].first << " " << 0 << endl;
        return 0;
    }
    sort(a.begin(), a.end());
    int begin_timer = a[0].first, end_timer = a[0].second;
    int most = end_timer - begin_timer, least = 0;
    for(int i = 1; i < n; i++){
         if(a[i].first <= end_timer){
            if(a[i].second > end_timer)
                end_timer = a[i].second;
         }else{
            least = max(least, a[i].first - end_timer);
            begin_timer = a[i].first;
            end_timer = a[i].second;
         }
         most = max(most, end_timer - begin_timer);
    }

    cout << most << " " << least << endl;
}
