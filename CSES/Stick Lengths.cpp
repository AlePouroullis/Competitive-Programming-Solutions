#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int middle = a[n/2];
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += abs(a[i]-middle);
    }
    cout << ans << endl;
}
