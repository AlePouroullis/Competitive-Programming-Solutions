// Parts of the solution borrowed from Coding with Dongs' YouTube channel.
/*
ID: ---
LANG: C++
TASK: crypt1
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

int n, *nums;

bool inset(int num){
    while(num){
        int digit = num % 10;
        bool flag = false;
        for(int i = 0; i < n; i++){
            if(digit == nums[i]){
                flag = true;
                break;
            }
        }
        if(!flag)
            return false;
        num /= 10;
    }
    return true;
}

int main(){
    fast
    ifstream cin("crypt1.in");
    ofstream cout("crypt1.out");

    cin >> n;
    nums = new int[n];
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    int ans = 0;
    for(int a = 0; a < n; a++){
        for(int b = 0; b < n; b++){
            for(int c = 0; c < n; c++){
                for(int d = 0; d < n; d++){
                    for(int e = 0; e < n; e++){
                        int num1 = (nums[a]*100 + nums[b]*10 + nums[c]);
                        int partial1;
                        partial1 =  nums[e] * num1;

                        if(inset(partial1) && partial1 < 1000){
                            int partial2 = nums[d] * num1;
                            if(inset(partial2) && partial2 < 1000){
                                int sum = partial1 + partial2*10;
                                if(inset(sum) && sum < 10000)
                                    ans++;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;
}
