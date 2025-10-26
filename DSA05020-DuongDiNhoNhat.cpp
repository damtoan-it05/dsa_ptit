#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int dx[3] = {-1, -1, 0};
int dy[3] = {-1, 0, -1};

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        int n, m;
        cin >> n >> m;
        int a[n+1][m+1];
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> a[i][j];
            }
        }
        int dp[n+1][m+1];
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int tmp = INT_MAX;
                for(int k = 0; k < 3; k++){
                    int i1 = i + dx[k];
                    int j1 = j + dy[k];
                    if((i1 >= 1) and (i1 <= n) and (j1 >= 1) and (j1 <= m)){
                        tmp = min(tmp, dp[i1][j1]);
                    }
                }
                if(tmp != INT_MAX){
                    dp[i][j] = a[i][j] + tmp;
                }
                else{
                    dp[i][j] = a[i][j];
                }
            }
        }
        cout << dp[n][m] << endl;
    }
}