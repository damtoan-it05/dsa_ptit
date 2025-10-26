#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    string a[n+1];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int X[k];
    for(int i = 0; i < k; i++){
        X[i] = i;
    }
    int res = INT_MAX;
    do{
        int maxs = INT_MIN, mins = INT_MAX;
        for(int i = 0; i < n; i++){
            string s = "";
            for(int l = 0; l < k; l++){
                s += a[i][X[l]];
            }
            maxs = max(maxs, stoi(s));
            mins = min(mins, stoi(s));
        }
        res = min(res, maxs - mins);
    } while(next_permutation(X, X + k));
    cout << res << endl;
}