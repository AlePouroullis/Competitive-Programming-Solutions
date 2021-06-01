#include <bits/stdc++.h>

using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back

int n, p[20];
ll ans = 0;

int divide(int i = 0, ll sum1 = 0, ll sum2 = 0){
    if(i == n)
        return abs(sum1-sum2);

    return min(divide(i + 1, sum1 + p[i], sum2),
               divide(i + 1, sum1, sum2 + p[i]));
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> p[i];
    cout << divide() << endl;
}
