#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main(){
    int n;
    cin >> n;
    ll res = 0;
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        if(x > 0){
            res += (2 * x);
        }
    }
    cout << res << endl;
}