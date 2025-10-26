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
        int dp[maxn][maxn]; // Độ dài xâu con đối xứng dài nhất ko liên tiếp trong đoạn [i, j]
        memset(dp, 0, sizeof(dp));
        for(int i = n; i >= 1; i--){
            for(int j = i; j <= n; j++){
                if(i == j){
                    dp[i][j] = 1;
                }
                else if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        cout << n - dp[1][n] << endl;
    }
}