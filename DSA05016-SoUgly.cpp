#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

vector<ll> res;

void init(){
    map<ll,ll> mp;
    queue<ll> Q;
    Q.push(1);
    mp[1] = 1;
    while(Q.front() <= 1e18){
        ll x = Q.front(); Q.pop();
        res.push_back(x);
        if(!mp[2*x]){
            Q.push(2*x);
            mp[2*x] = 1;
        }
        if(!mp[3*x]){
            Q.push(3*x);
            mp[3*x] = 1;
        }
        if(!mp[5*x]){
            Q.push(5*x);
            mp[5*x] = 1;
        }
    }
    sort(begin(res), end(res));
}

int main(){
    init();
    int TC;
    cin >> TC;
    while(TC--){
        int n;
        cin >> n;
        cout << res[n-1] << endl;
    }
}