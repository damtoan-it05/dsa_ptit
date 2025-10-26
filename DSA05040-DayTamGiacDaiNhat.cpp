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
        for(auto &x : a){
            cin >> x;
        }
        vector<int> dp1(n, 1);
        vector<int> dp2(n, 1); 
        for(int i = 1; i < n; i++){
            if(a[i] > a[i-1]){
                dp1[i] = max(dp1[i], dp1[i-1] + 1);
            }
        }
        for(int i = (n-2); i >= 0; i--){
            if(a[i] > a[i+1]){
                dp2[i] = max(dp2[i], dp2[i+1] + 1);
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            res = max(res, dp1[i] + dp2[i] - 1);
        }
        cout << res << endl;
    }
}