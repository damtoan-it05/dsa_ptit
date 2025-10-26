#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        int n;
        cin >> n;
        int a[n];
        for(auto &x : a){
            cin >> x;
        }
        vector<int> dp(a, a + n);
        dp[1] = max(dp[1], dp[0]);
        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i-1], dp[i-2] + a[i]);
        }
        cout << dp[n-1] << endl;
    }   
}