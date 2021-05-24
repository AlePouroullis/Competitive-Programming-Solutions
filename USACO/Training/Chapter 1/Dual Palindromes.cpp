// Solution by Alexandros Pouroullis
/*
Helper functions borrowed from the Palindromic Squares problem.
*/
/*
ID: ---
LANG: C++
TASK: dualpal
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

string base_b(int num, int base){
    int dividend = num, rem;
    string base_b_string = "";
    while(dividend > 0){
        rem = dividend % base;
        if(rem > 9){
            base_b_string.insert(0, 1, (char)(rem - 10 + (int)'A'));
        }else{
            base_b_string.insert(0, 1, (char)(rem + (int)'0'));
        }
        dividend /= base;
    }

    return base_b_string;
}

bool is_palindrome(string b){
    int mid = b.length() / 2;
    string first_half;
    string second_half;
    if(b.length() > 1){
        first_half = b.substr(0, mid);
        if(b.length() % 2 == 0){
            second_half = b.substr(mid);
        }else{
            second_half = b.substr(mid + 1);
        }
        reverse(second_half.begin(), second_half.end());
        if(first_half == second_half){
            return true;
        }
    }else{
        return true;
    }
    return false;
}

int main(){
    fast
    ifstream cin("dualpal.in");
    ofstream cout("dualpal.out");
    int n, s;
    cin >> n >> s;
    while(n > 0){
        s++;
        int cnt = 0;
        for(int i = 2; i <= 10; i++){
            if(is_palindrome(base_b(s, i)))
                cnt++;
            if(cnt == 2){
                cout << s << endl;
                n--;
                break;
            }
        }
    }
}
