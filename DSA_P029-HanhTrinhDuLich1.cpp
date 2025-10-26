#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 20;

int n, C[maxn][maxn], dp[1 << 16][maxn];

/*
- mask: Lưu trạng thái các thành phố đã đi qua (Số bit được bật)
- i: Là thành phố kết thúc của trạng thái mask (Là 1 bit được bật trong mask)
- dp[mask][i]: Là chi phí tối thiểu để đi qua mask thành phố và kết thúc tại thành phố i
*/

void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> C[i][j];
        }
    }
}

bool Get_Bit(int mask, int i){
    return mask & (1 << i);
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        input();
        for(int mask = 1; mask < (1 << n); mask++){
            // Bỏ qua các thành phố chỉ có 1 bit 1, tức trạng thái trước đó khi tắt 1 bit thì nó chưa đi qua tp nào cả
            if(__builtin_popcount(mask) != 1){
                for(int i = 0; i < n; i++){
                    if(Get_Bit(mask, i)){
                        int pre_mask = mask & (~(1 << i)); // Tắt bit 1 ở vị trí i
                        dp[mask][i] = INT_MAX;
                        for(int j = 0; j < n; j++){
                            if(Get_Bit(pre_mask, j)){
                                // Xét tất cả các thành phố j trong pre_mask làm điểm kết thúc
                                dp[mask][i] = min(dp[mask][i], dp[pre_mask][j] + C[j][i]);
                            }
                        }
                    }
                }
            }
        }
        int ans = INT_MAX;
        for(int j = 0; j < n; j++){
            ans = min(ans, dp[(1 << n) - 1][j]);
        }
        cout << ans << endl;
    }
}