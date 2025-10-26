#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 101;
const int MOD = 1e9 + 7;

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        int n; cin >> n;
        ll dp[maxn][maxn]; // dp[i][j]: Lưu số số có i chữ số kết thúc bằng j
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= 9; j++){
                if((i == 1) or (j == 0)){
                    dp[i][j] = 1;
                }
                else{
                    ll tmp = 0;
                    for(int k = 0; k <= j; k++){
                        tmp += dp[i-1][k];
                        tmp %= MOD;
                    }
                    dp[i][j] = tmp;
                }
            }
        }
        ll res = 0;
        for(int i = 0; i <= 9; i++){
            res += dp[n][i];
            res %= MOD;
        }
        cout << res << endl;
    }
}