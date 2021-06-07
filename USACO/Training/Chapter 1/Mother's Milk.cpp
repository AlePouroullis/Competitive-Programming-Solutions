// Code idea borrowed from Coding with Dong
/*
ID : ---
LANG: C++
TASK : milk3
*/

#include <bits/stdc++.h>

using namespace std;

int A, B, C;
vector<int> solutions;
bool visited[21][21][21];

void dfs(int a, int b, int c){
    if(visited[a][b][c])
        return;

    visited[a][b][c] = true;

    if(a == 0)
        solutions.push_back(c);

    // a->b
    dfs(a - min(a, B-b), b + min(a, B-b), c);
    // a->c
    dfs(a - min(a, C-c), b, c + min(a, C-c));
    // b->a
    dfs(a + min(b, A-a), b - min(b, A-a), c);
    // b->c
    dfs(a, b - min(b, C-c), c + min(b, C-c));
    // c->a
    dfs(a + min(c, A-a), b, c - min(c, A-a));
    // c->b
    dfs(a, b + min(c, B-b), c - min(c, B-b));

}

int main(){
    ifstream cin("milk3.in");
    ofstream cout("milk3.out");

    cin >> A >> B >> C;

    dfs(0, 0, C);

    sort(solutions.begin(), solutions.end());

    for(int i = 0; i < solutions.size(); i++){
        if(i != solutions.size()-1)
            cout << solutions[i] << " ";
        else
            cout << solutions[i] << endl;
    }
}
