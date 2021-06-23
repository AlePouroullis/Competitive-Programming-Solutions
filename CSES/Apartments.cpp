#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    int desired[n];
    int apartments[m];
    for(int i = 0; i < n; i++)
        cin >> desired[i];
    for(int i = 0; i < m; i++)
        cin >> apartments[i];
    sort(desired, desired + n);
    sort(apartments, apartments + m);
    int ans = 0;
    int i = 0, j = 0;
    while(i < n && j < m){
        if(abs(desired[i]-apartments[j]) <= k){
            ans++;
            i++; j++;
        }else if(desired[i] - apartments[j] > k)
            j++;
        else
            i++;
    }
    cout << ans << endl;
}
