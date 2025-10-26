#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        int n, k;
        cin >> n >> k;
        int a[n];
        for(auto &x : a){
            cin >> x;
        }
        sort(a, a + n);
        ll ans = 0;
        for(int i = 0; i < (n - 1); i++){
            auto it = lower_bound(a + i + 1, a + n, k + a[i]);
            --it;
            ans += 1ll * (it - (a + i));
        }
        cout << ans << endl;
    }
}