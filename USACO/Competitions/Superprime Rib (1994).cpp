// Solution by Alexandros Pouroullis 
// The largest superprime number is 8 digits long: 73939133
#include <bits/stdc++.h>

using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back

int n;
int num = 0;
vector<int> solutions;

bool is_prime(int num){
    if(num < 2) return false;
    if(num == 2 || num == 3) return true;
    if(!(num % 6 == 1 || num % 6 == 5)) return false;
    for(int i = 2; i*i <= num; i++)
        if(num % i == 0)
            return false;
    return true;
}

void dfs(int num_length){
    if(num_length > 0)
        if(!is_prime(num))
            return;

    if(num_length == n){
        if(is_prime(num))
            solutions.push_back(num);
        return;
    }

    if(num_length > 0){
        for(int i = 1; i <= 9; i+=2){
            num *= 10;
            num += i;
            dfs(num_length+1);
            num -= i;
            num /= 10;
        }
    }else{
        for(int i = 1; i <= 9; i++){
            num += i;
            dfs(num_length+1);
            num -= i;
        }
    }
}

int main(){
    cin >> n;
    dfs(0);
    for(int prime : solutions){
        cout << prime << endl;
    }
}
