#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream cin("hps.in");
    ofstream cout("hps.out");
    int n;
    cin >> n;
    int paper[n+1] = {0}, hoof[n+1] = {0}, scissors[n+1] = {0};
    for(int i = 0; i < n; i++){
        paper[i+1] += paper[i];
        hoof[i+1] += hoof[i];
        scissors[i+1] += scissors[i];
        char gesture;
        cin >> gesture;
        if(gesture == 'P')
            paper[i+1]++;
        else if(gesture == 'H')
            hoof[i+1]++;
        else
            scissors[i+1]++;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, paper[i] + max(hoof[n] - hoof[i], scissors[n] - scissors[i]));
        ans = max(ans, hoof[i] + max(paper[n] - paper[i], scissors[n] - scissors[i]));
        ans = max(ans, scissors[i] + max(paper[n] - paper[i], hoof[n] - hoof[i]));
    }

    cout << ans << endl;
}
