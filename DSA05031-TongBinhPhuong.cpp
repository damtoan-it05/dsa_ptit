#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 10001;

int dp[maxn];

void init(){
    dp[1] = 1;
    for(int n = 2; n <= 10000; n++){
        dp[n] = n;
        for(int j = 1; j <= sqrt(n); j++){
            dp[n] = min(dp[n], 1 + dp[n-j*j]);
        }
    }
}

int main(){
    init();
    int TC;
    cin >> TC;
    while(TC--){
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
}