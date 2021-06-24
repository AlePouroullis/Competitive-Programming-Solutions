#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> x;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        int lo = 0, hi = x.size();
        while(lo < hi){
            int mid = lo + (hi - lo)/2;
            if(x[mid] > val) hi = mid;
            else lo = mid + 1;
        }
        if(lo == x.size()) x.push_back(val);
        else x[lo] = val;
    }
    cout << x.size() << endl;
}
