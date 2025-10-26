#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        int n; cin >> n;
        double a[n+1], b[n+1];
        for(int i = 1; i <= n; i++){
            cin >> a[i] >> b[i];
        }
        vector<int> dp(n + 1, 1);
        for(int i = 2; i <= n; i++){
            for(int j = 1; j < i; j++){
                if((a[i] > a[j]) and (b[i] < b[j])){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        cout << *max_element(dp.begin() + 1, dp.end()) << endl;
    }
}