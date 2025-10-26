#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        int N, insert, deleted, copying;
        cin >> N >> insert >> deleted >> copying;
        int dp[N+1] = {0}; // Chi phí tối thiểu để tạo ra chuỗi giống nhau độ dài i
        dp[1] = insert;
        for(int i = 2; i <= N; i++){
            if(i & 1){
                dp[i] = min(dp[i-1] + insert, dp[i/2 + 1] + copying + deleted);
            }
            else{
                dp[i] = min(dp[i-1] + insert, dp[i/2] + copying);
            }
        }
        cout << dp[N] << endl;
    }
}