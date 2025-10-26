#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 10001;

int n, a[4][maxn], dp[maxn][20], mark[20];

bool Get_Bit(int n, int i){
    // return ((n >> i) & 1);
    return ((1 << i) & n);
}

void init(){
    for(int mask = 0; mask < (1 << 4); mask++){
        bool check = 1;
        for(int i = 1; i <= 3; i++){
            if((Get_Bit(mask, i)) && (Get_Bit(mask, i-1))){
                check = 0;
                break;
            }
        }
        mark[mask] = check;
    }
}

int main(){
    init();
    int TC;
    cin >> TC;
    while(TC--){
        cin >> n;
        int res = INT_MIN;
        for(int i = 0; i <= 3; i++){
            for(int j = 1; j <= n; j++){
                cin >> a[i][j];
                res = max(res, a[i][j]);
            }
        }
        if(res < 0){
            cout << res << endl;
            continue;
        }
        res = INT_MIN;
        for(int j = 1; j <= n; j++){
            for(int mask = 0; mask < (1 << 4); mask++){
                if(mark[mask]){
                    int sum = 0;
                    for(int i = 0; i <= 3; i++){
                        if(Get_Bit(mask, i)){
                            sum += a[i][j];
                        }
                    }
                    dp[j][mask] = INT_MIN;
                    for(int prev_mask = 0; prev_mask < (1 << 4); prev_mask++){
                        if((mark[prev_mask]) && (!(prev_mask & mask))){
                            dp[j][mask] = max(dp[j][mask], dp[j-1][prev_mask] + sum);
                        }
                    }
                    res = max(res, dp[j][mask]);
                }
            }
        }
        cout << res << endl;
    }
}