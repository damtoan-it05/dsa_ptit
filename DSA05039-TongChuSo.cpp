#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxA = 100;
const int maxB = 10000;

int dp[101][10001]; // Lưu số chữ số tối thiểu của số có tổng cs là i và tổng bình phương cs là j

void init(){
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 0; i <= maxA; i++){
        for(int j = 0; j <= maxB; j++){
            if(dp[i][j] != -1){
                for(int k = 1; k <= 9; k++){
                    int i1 = i + k;
                    int j1 = j + k * k;
                    if((i1 <= maxA) and (j1 <= maxB)){
                        if((dp[i1][j1] == -1) or (dp[i1][j1] > dp[i][j] + 1)){
                            dp[i1][j1] = dp[i][j] + 1;
                        }
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
        int a, b;
        cin >> a >> b;
        if(dp[a][b] == -1){
            cout << "-1" << endl;
            continue;
        }
        while((a > 0) and (b > 0)){
            for(int k = 1; k <= 9; k++){
                int x = a - k;
                int y = b - k * k;
                if((x >= 0) && (y >= 0) && (dp[a][b] == dp[x][y] + 1)){
                    cout << k;
                    a -= k;
                    b -= k*k;
                    break;
                }
            }
        }
        cout << endl;
    }
}