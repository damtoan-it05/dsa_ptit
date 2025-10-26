#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 100;

string s;
int n, X[maxn];
ll res = 0;
bool flag = true;

bool check(ll x){
    ll tmp = cbrt(x) + 0.5;
    return (tmp * tmp * tmp) == x;
}

void Try(int i){
    for(int j = 0; j <= 1; j++){
        X[i] = j;
        if(i == n){
            string ans = "";
            for(int l = 1; l <= n; l++){
                if(X[l]){
                    ans += s[l];
                }
            }
            if((ans != "") and (check(stoll(ans)))){
                res = max(res, stoll(ans));
                flag = false;
            }
        }
        else{
            Try(i + 1);
        }
    }
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        cin >> s;
        n = s.size();
        s = " " + s;
        res = 0;
        flag = true;
        Try(1);
        if(!flag){
            cout << res << endl;
        }
        else{
            cout << "-1" << endl;
        }
    }
}