#include <bits/stdc++.h>

using namespace std;

int n;
string grid[10];

void tip(int row, int col){
    for(int i = row; i >= 0; i--){
        for(int j = col; j >= 0; j--){
            if(grid[i][j] == '1')
                grid[i][j] = '0';
            else
                grid[i][j] = '1';
        }
    }
}

int main(){
    ifstream cin("cowtip.in");
    ofstream cout("cowtip.out");
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> grid[i];

    int ans = 0;
    for(int i = n-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            if(grid[i][j] == '1'){
                tip(i, j);
                ans++;
            }
        }
    }

    cout << ans << endl;
}
