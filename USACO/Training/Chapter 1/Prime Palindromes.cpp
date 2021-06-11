/*
ID : ---
LANG: C++
TASK : pprime
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

vector<int> ans;
int a, b;

bool is_prime(int num){
    if(num < 2) return false;
    if(num == 2 || num == 3) return true;
    if(!(num % 6 == 1 || num % 6 == 5)) return false;
    for(int i = 2; i*i <= num; i++)
        if(num % i == 0)
            return false;
    return true;
}

bool check(int num){
    if(num < a || num > b) return false;
    if(is_prime(num)) return true;
    return false;
}

int main(){
    ifstream cin("pprime.in");
    ofstream cout("pprime.out");

    cin >> a >> b;

    // 1 digit numbers:
    for(int d1 = 1; d1 <= 9; d1++){
        if(check(d1)) ans.push_back(d1);
    }

    // The only even numbered digit palindromic prime is 11.
    /*
    Explanation by Mohammad Afzaal Butt on Quora.
    Let N=a0a1a2a2a1a0 be any six digit palindromic number. Then
    N=a0a1a2a2a1a0
    =10^5a0+10^4a1+10^3a2+10^2a2+10a1+a0
    =(10^5+1)a0+(10^4+10)a1+(10^3+10^2)a2
    =100001a0+10010a1+1100a2
    =11*9091a0+11*910a1+11*100a2
    =11(9091a0+910a1+100a2)

    Above applies for all even numbered digit palindromic primes.
    */
    if(11 >= a && 11 <= b) ans.push_back(11);
    // 3 digit numbers:
    for(int d1 = 1; d1 <= 9; d1+=2){
        for(int d2 = 0; d2 <= 9; d2++){
            int num = d1*100 + d2*10 + d1;
            if(check(num)) ans.push_back(num);
        }
    }

    // 5 digit numbers:
    for(int d1 = 1; d1 <= 9; d1+=2){
        for(int d2 = 0; d2 <= 9; d2++){
            for(int d3 = 0; d3 <= 9; d3++){
                int num = d1*10000 + d2*1000 + d3*100 + d2*10 + d1;
                if(check(num)) ans.push_back(num);
            }
        }
    }

    // 7 digit numbers:
    for(int d1 = 1; d1 <= 9; d1+=2){
        for(int d2 = 0; d2 <= 9; d2++){
            for(int d3 = 0; d3 <= 9; d3++){
                for(int d4 = 0; d4 <= 9; d4++){
                    int num = d1*1000000 + d2*100000 + d3*10000 + d4*1000 + d3*100 + d2*10 + d1;
                    if(check(num)) ans.push_back(num);
                }
            }
        }
    }

    // 9 digits numbers:
    for(int d1 = 1; d1 <= 9; d1+=2){
        for(int d2 = 0; d2 <= 9; d2++){
            for(int d3 = 0; d3 <= 9; d3++){
                for(int d4 = 0; d4 <= 9; d4++){
                    for(int d5 = 0; d5 <= 9; d5++){
                        int num = d1*100000000 + d2*10000000 + d3*1000000 + d4*100000 +
                        d5*10000 + d4*1000 + d3*100 + d2*10 + d1;
                        if(check(num)) ans.push_back(num);
                    }
                }
            }
        }
    }

    for(int answer : ans){
        cout << answer << endl;
    }
}
