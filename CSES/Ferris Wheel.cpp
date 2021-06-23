#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    int p[n];
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    sort(p, p + n);
    int right = n-1, left = 0;
    int ans = 0;
    while(right >= left){
        if(p[right] + p[left] <= x){
            ans++;
            right--;
            left++;
        }else if(p[right] <= x){
            ans++;
            right--;
        }
    }
    cout << ans << endl;
}
