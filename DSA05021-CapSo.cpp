#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        int n;
        cin >> n;
        pair<int,int> a[n];
        for(auto &x : a){
            cin >> x.first >> x.second;
        }
        sort(a, a + n);
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(a[i].first > a[j].second){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        cout << *max_element(dp.begin(), dp.end()) << endl;
    }
}