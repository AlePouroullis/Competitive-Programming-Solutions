#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream cin("bcount.in");
    ofstream cout("bcount.out");
    int n, q;
    cin >> n >> q;
    int holsteins[n] = {0}, guernseys[n] = {0},
    jerseys[n] = {0}, cows[n];
    for(int i = 0; i < n; i++){
        cin >> cows[i];
    }
    for(int i = 0; i < n; i++){
        if(cows[i] == 1)
            holsteins[i]++;
        else if(cows[i] == 2)
            guernseys[i]++;
        else if(cows[i] == 3)
            jerseys[i]++;
    }
    for(int i = 1; i < n; i++){
        holsteins[i] = holsteins[i] + holsteins[i-1];
        guernseys[i] = guernseys[i] + guernseys[i-1];
        jerseys[i] = jerseys[i] + jerseys[i-1];
    }
    while(q--){
        int a, b;
        cin >> a >> b;
        a--; b--;
        if(a == 0){
            cout << holsteins[b] << " " <<
            guernseys[b] << " " <<
            jerseys[b] << endl;
        }else{
            cout << holsteins[b] - holsteins[a-1] << " " <<
            guernseys[b] - guernseys[a-1] << " " <<
            jerseys[b] - jerseys[a-1] << endl;
        }
    }
}
