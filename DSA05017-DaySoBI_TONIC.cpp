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
        int a[n];
        for(auto &x : a) cin >> x;
        vector<int> dp1(a, a + n);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(a[i] > a[j]){
                    dp1[i] = max(dp1[i], dp1[j] + a[i]);
                }
            }
        }
        vector<int> dp2(a, a + n);
        for(int i = (n - 2); i >= 0; i--){
            for(int j = (n - 1); j > i; j--){
                if(a[i] > a[j]){
                    dp2[i] = max(dp2[i], dp2[j] + a[i]);
                }
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            res = max(res, dp1[i] + dp2[i] - a[i]);
        }
        cout << res << endl;
    }
}