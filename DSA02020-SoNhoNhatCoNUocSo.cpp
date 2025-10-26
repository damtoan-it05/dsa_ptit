#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

ll prime[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

ll n, res = 1e18;

void Try(int i, ll val, ll cnt){
    if(cnt == n) res = min(res, val);
    if(cnt > n) return;
    for(int j = 1; ; j++){
        if((val * prime[i]) > res) break;
        val *= prime[i];
        Try(i + 1, val, cnt * (j + 1));
    }
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        cin >> n;
        res = 1e18;
        Try(0, 1, 1);
        cout << res << endl;
    }
}