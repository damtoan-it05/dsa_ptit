#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 101;

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        string s;
        cin >> s;
        int n = s.size();
        s = " " + s;
        int dp[maxn][maxn];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++){
            dp[i][i] = 1;
        }
        for(int len = 2; len <= n; len++){
        for(int i = 1; i <= (n - len + 1); i++){
            int j = i + len - 1;
            if(s[i] == s[j]){
                if(len == 2){
                    dp[i][j] = 2;
                }
                else{
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
            }
            else{
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
        cout << n - dp[1][n] << endl;
    }
}