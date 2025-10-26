#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 101;
const int MOD = 1e9 + 7;

ll dp[maxn][maxn]; // dp[i][j]: Lưu số số có i chữ số kết thúc bằng j

/*
- Base case: 
+ Số số có 1 chữ số (i = 1) là 1 => dp[1][j] = 1
+ Số số có chữ số kêt thúc bằng 0 (j = 0) là 1 => dp[i][0] = 1
- CTQHĐ:
+ dp[i][j] = Tổng dp[i-1][k] với (k : 0 -> j)
*/

void init(){
    for(int i = 1; i <= 100; i++){
        for(int j = 0; j <= 9; j++){
            if((i == 1) or (j == 0)){
                dp[i][j] = 1;
            }
            else{
                for(int k = 0; k <= j; k++){
                    dp[i][j] += dp[i-1][k];
                    dp[i][j] %= MOD;
                }
            }
        }
    }
}

int main(){
    init();
    int TC;
    cin >> TC;
    while(TC--){
        int n; 
        cin >> n;
        ll res = 0;
        for(int j = 0; j <= 9; j++){
            res += dp[n][j];
            res %= MOD;
        }
        cout << res << endl;
    }
}