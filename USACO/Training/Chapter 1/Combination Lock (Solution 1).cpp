/*
ID: ---
LANG: C++
TASK: combo
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

int n, *dial1, *dial2;
// By using a set, repeated permutations as a result of the intersection of
// the two dial combinations are eliminated.
set<tuple<int, int, int>> permutations;

void perms(int *dial){

    for(int a = -2; a <= 2; a++){
        for(int b = -2; b <= 2; b++){
            for(int c = -2; c <= 2; c++){
                permutations.insert({(n+(dial[0]+a))%n + 1,
                    (n+(dial[1]+b))%n + 1,
                    (n+(dial[2]+c))%n + 1});
            }
        }
    }
}

int main(){
    ifstream cin("combo.in");
    ofstream cout("combo.out");
    cin >> n;
    int dial1[3], dial2[3];
    cin >> dial1[0] >> dial1[1] >> dial1[2];
    cin >> dial2[0] >> dial2[1] >> dial2[2];

    // Subtracting dial numbers by 1 makes modular arithmetic more
    // intuitive.
    dial1[0]--; dial1[1]--; dial1[2]--;
    dial2[0]--; dial2[1]--; dial2[2]--;
    perms(dial1);
    perms(dial2);

    cout << permutations.size() << endl;
}
