#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int MOD = 1e9 + 7;

ll dp[105][50005]; // dp[i][j]: Số các số có i chữ số và tổng là j

void init(){
    for(int i = 1; i <= 100; i++){
        for(int j = 0; j <= 50000; j++){
            if((i == 1) && (j <= 9) && (j >= 1)){
                dp[i][j] = 1;
            }
            else if(j == 0){
                dp[i][j] = 0;
            }
            else{
                for(int k = 0; k <= 9; k++){
                    if((j - k) >= 0){
                        dp[i][j] += dp[i-1][j-k];
                        dp[i][j] %= MOD;
                    }
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
        int n, k;
        cin >> n >> k;
        cout << dp[n][k] << endl;
    }
}