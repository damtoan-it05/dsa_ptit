#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        int n, k;
        cin >> n >> k;
        int a[n+1];
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            a[i] %= k;
        }
        // dp[i][j]: Lưu dãy con dài nhất nếu lấy 1->i phần tử và tổng phần tử chia dư cho k là j
        int dp[n+1][k]; 
        // Base case
        for(int j = 0; j < k; j++){
            if(j == 0){
                dp[0][j] = 0;
            }
            else{
                dp[0][j] = INT_MIN;
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < k; j++){
                dp[i][j] = max(dp[i-1][j], dp[i-1][(j - a[i] + k) % k] + 1);
            }
        }
        cout << dp[n][0] << endl;
    }
}