// Solution by Alexandros Pouroullis
// This solution is a more efficient alternative to the other solution I have available, by using
// binary search.
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
                int left = 0;
                int right = low_idx;
                int lower = low_idx;
                while(left <= right){
                    int mid = left + (right - left)/2;
                    if(bales[mid] < bales[low_idx] - t){
                        left = mid + 1;
                    }else{
                        lower = mid;
                        right = mid - 1;
                    }
                }
                low_idx = lower;
            }

            if(high_idx == n-1 || bales[high_idx+1] > bales[high_idx] + t)
                stopRight = true;

            if(!stopRight){
                int left = high_idx;
                int right = n-1;
                int upper = high_idx;
                while(left <= right){
                    int mid = left + (right - left)/2;
                    if(bales[mid] > bales[high_idx] + t){
                        right = mid-1;
                    }else{
                        upper = mid;
                        left = mid + 1;
                    }
                }
                high_idx = upper;
            }
        }
        ans = max(ans, high_idx - low_idx + 1);
    }

    cout << ans << endl;
}
