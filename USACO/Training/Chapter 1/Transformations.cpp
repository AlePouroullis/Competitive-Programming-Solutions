// Solution by Alexandros Pouroullis
/*
Not the most efficient solution since it was unnecessary to create
the 180 and 270 degree rotation functions, because you could just rotate
the square by 90 2 or 3 times to check if the second square is the first square
rotated 180 or 270 degrees. In any case, a nice problem to practice one's implementation
skills. 
*/

/*
ID: tranform
LANG: C++
TASK: transform
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

int n;
// i: initial; t: transformed.
vector<vector<char>> isquare(10, vector<char> (10)), tsquare(10, vector<char> (10));

bool is_90_degree_rotation(vector<vector<char>> square1 = isquare, vector<vector<char>> square2 = tsquare){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(square1[n - j - 1][i] != square2[i][j]){
                return false;
            }
        }
    }
    return true;
}

bool is_180_degree_rotation(vector<vector<char>> square1 = isquare, vector<vector<char>> square2 = tsquare){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(square1[i][j] != square2[n - i - 1][n - j - 1])
                return false;
        }
    }
    return true;
}

bool is_270_degree_rotation(vector<vector<char>> square1 = isquare, vector<vector<char>> square2 = tsquare){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(isquare[j][n - i - 1] != tsquare[i][j])
                return false;
        }
    }
    return true;
}

bool is_reflection(vector<vector<char>> square1 = isquare, vector<vector<char>> square2 = tsquare){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(square1[i][n - j - 1] != square2[i][j])
                return false;
        }
    }
    return true;
}

bool is_combination(vector<vector<char>> square1 = isquare, vector<vector<char>> square2 = tsquare){
    vector<vector<char>> reflected_square(10, vector<char>(10));
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n; j++){
            reflected_square[i][j] = isquare[i][n - j - 1];
        }
    }
    if(is_90_degree_rotation(reflected_square))
        return true;
    else if(is_180_degree_rotation(reflected_square))
        return true;
    else if(is_270_degree_rotation(reflected_square))
        return true;
    return false;
}


bool is_the_same(vector<vector<char>> square1 = isquare, vector<vector<char>> square2 = tsquare){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(isquare[i][j] != tsquare[i][j])
                return false;
        }
    }
    return true;
}

int main(){
    ifstream cin("transform.in");
    ofstream cout("transform.out");

    cin >> n;

    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++)
            cin >> isquare[row][col];
    }
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++)
            cin >> tsquare[row][col];
    }

    if(is_90_degree_rotation()){
        cout << 1 << endl;
        return 0;
    }

    if(is_180_degree_rotation()){
        cout << 2 << endl;
        return 0;
    }

    if(is_270_degree_rotation()){
        cout << 3 << endl;
        return 0;
    }

    if(is_reflection()){
        cout << 4 << endl;
        return 0;
    }

    if(is_combination()){
        cout << 5 << endl;
        return 0;
    }

    if(is_the_same()){
        cout << 6 << endl;
        return 0;
    }

    // If the transformed square was not the same as the initial square and
    // none of the transformations specified were applied to the square:
    cout << 7 << endl;
}
