#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 100;

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        int n, m;
        cin >> n >> m;
        ll dp[maxn][maxn];
        memset(dp, 0, sizeof(dp));
        dp[n][m] = 1;
        for(int i = n; i >= 0; i--){
            for(int j = m; j >= 0; j--){
                dp[i][j] += (dp[i+1][j] + dp[i][j+1]);
            }
        }
        cout << dp[0][0] << endl;
    }
}