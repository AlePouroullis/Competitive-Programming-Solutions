#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream cin("div7.in");
    ofstream cout("div7.out");
    int n;
    cin >> n;
    int ans = 0;
    int curr_remainder = 0;
    int first[7];
    memset(first, -1, sizeof(first));
    for(int i = 0; i < n; i++){
        int ID;
        cin >> ID;

        int curr_remainder = (curr_remainder + ID) % 7;
        if(first[curr_remainder] == -1){
            first[curr_remainder] = i;
        }else{
            ans = max(ans, i - first[curr_remainder]);
        }
    }

    cout << ans << endl;
}
