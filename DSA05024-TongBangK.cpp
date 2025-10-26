#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        int n, k;
        cin >> n >> k;
        int a[n];
        for(auto &x : a){
            cin >> x;
        }
        ll dp[k+1] = {1}; // dp[0] = 1
        for(int i = 1; i <= k; i++){
            for(int j = 0; j < n; j++){
                if(i >= a[j]){
                    dp[i] += dp[i - a[j]];
                    dp[i] %= MOD;
                }
            }
        }
        cout << dp[k] << endl;
    }
}