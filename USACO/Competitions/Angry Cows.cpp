// Solution by Alexandros Pouroullis 
// Some ideas borrowed from LaiTeam's YouTube channel.
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
    ifstream cin("angry.in");
    ofstream cout("angry.out");
    int n;
    cin >> n;
    int bales[n];
    for(int i = 0; i < n; i++)
        cin >> bales[i];

    sort(bales, bales + n);

    int ans = 0;
    for(int i = 0; i < n; i++){
        int t = 0;
        int lower = -1;

        if(i > 0){
            lower = bales[i-1];
        }

        int upper = INT_MAX;
        if(i < n-1)
            upper = bales[i+1];

        int low_idx = i;
        int high_idx = i;
        bool stopLeft = false, stopRight = false;
        while(!stopLeft || !stopRight){
            t++;
            if(low_idx == 0 || bales[low_idx-1] < bales[low_idx] - t)
                stopLeft = true;

            if(!stopLeft){
                int down = low_idx - 1;
                while(bales[down] >= bales[low_idx] - t && down >= 0){
                    down--;
                }
                low_idx = down+1;
            }

            if(high_idx == n-1 || bales[high_idx+1] > bales[high_idx] + t)
                stopRight = true;

            if(!stopRight){
                int up = high_idx + 1;
                while(bales[up] <= bales[high_idx] + t && up < n){
                    up++;
                }
                high_idx = up-1;
            }


        }
        ans = max(ans, high_idx - low_idx + 1);
    }

    cout << ans << endl;
}
