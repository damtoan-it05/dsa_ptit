#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 50;

int n, a[maxn][maxn], dp[1 << 21];

/*
- Gọi i là số bit 1 có trong mask
- dp[mask]: Lưu giá trị lớn nhất của hàng thứ i
*/

void input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
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
        memset(dp, 0, sizeof(dp));
        input();
        for(int i = 1; i <= n; i++){
            // Duyệt qua các hàng và tìm trạng thái thích hợp (Hàng i có i bit được bật)
            for(int mask = 1; mask < (1 << n); mask++){
                if(__builtin_popcount(mask) == i){
                    for(int j = 0; j < n; j++){
                        // Lấy ra từng bit được bật trong trạng thái hiện tại
                        if(Get_Bit(mask, j)){
                            int pre_mask = mask - (1 << j); // Tắt bit được bật để tìm trạng thái phía sau
                            dp[mask] = max(dp[mask], dp[pre_mask] + a[i][j+1]);
                        }
                    }
                }
            }
        }
        cout << dp[(1 << n) - 1] << endl;
    }
}