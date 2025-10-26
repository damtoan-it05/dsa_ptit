#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 505;

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        int n, m;
        cin >> n >> m;
        int a[maxn][maxn];
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> a[i][j];
            }
        }
        int dp[maxn][maxn];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if((i == 1) or (j == 1)){
                    dp[i][j] = a[i][j];
                }
                else{
                    if(a[i][j]){
                        dp[i][j] = min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]}) + 1;
                    }
                }
            }
        }
        int res = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                res = max(res, dp[i][j]);
            }
        }
        cout << res << endl;
    }
}