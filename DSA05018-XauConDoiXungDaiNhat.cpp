#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        string s; cin >> s;
        int n = s.size();
        s = " " + s;
        int dp[n+1][n+1]; // Xâu con bắt đầu ở chỉ số i và kết thúc ở j
        for(int i = 1; i <= n; i++){ // Cơ sở qhđ: Xâu con có 1 phần tử thì luôn đối xứng
            dp[i][i] = 1;
        }
        int res = 1;
        for(int len = 2; len <= n; len++){ // Duyệt qua các độ dài có thể của xâu con
            // Tìm chỉ số bắt đầu và kết thúc
            for(int i = 1; i <= (n - len + 1); i++){
                int j = i + len - 1;
                if(s[i] != s[j]){ // Nếu ở 2 đầu khác nhau thì ko thể tạo xâu đối xứng
                    dp[i][j] = 0;
                }
                else{ // Nếu ở 2 đầu giống nhau nhau
                    if(len == 2){ // Nếu độ dài bằng 2 thì xâu sẽ đối xứng
                        dp[i][j] = 1;
                    }
                    else{ // Nếu độ dài lớn hơn 2 thì xét sự đối xứng của xâu con thu hẹp
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                if(dp[i][j]){
                    res = max(res, len);
                }
            }
        }
        cout << res << endl;
    }
}