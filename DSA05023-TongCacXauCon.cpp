#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        string s;
        cin >> s;
        int n = s.size();
        s = " " + s;
        ll ans = 0;
        for(int len = 1; len <= n; len++){
            for(int i = 1; i <= (n - len + 1); i++){
                ans += stoll(s.substr(i, len));
            }
        }
        cout << ans << endl;
    }
}